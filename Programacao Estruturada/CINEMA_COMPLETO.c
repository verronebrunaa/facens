/*
Fazer um programa de Sistema de Reserva de Ingressos para Cinema. Alocar dinamicamente
espaço e cadastrar 3 salas de cinemas, iniciar a quantidade de ingressos com 20. Em seguida, fazer o
menu para:

[1] Reserva – mostrar todas as informações da struct cinema. Em seguida, alocar dinamicamente
espaço para 1 cliente, receber o CPF, nome do cliente, o nome do filme e a quantidade de ingressos
desejados. Buscar o número da sala, de acordo com o nome do filme e quantidade de ingressos
disponíveis. Apresentar o número da sala e o valor total a ser pago pelo cliente e não esquecer
de:
? na estrutura cliente: guardar o número da sala e a quantidade de ingressos
? na estrutura cinema: atualizar a quantidade de ingressos (subtrair)

[2] Desistência – encerra a reserva pelo CPF do cliente. Mostrar o nome do cliente, o nome do
filme, a quantidade de ingressos que haviam sido reservados e o valor total a ser devolvido para o
cliente. Não esquecer de:
? na estrutura cliente: mudar o número da sala para -1
? na estrutura cinema: acrescer a quantidade de ingressos devolvidos ao total disponível
[3] Fim

Utilizar ponteiro para cinema e ponteiro para cliente e fazer as funções:
aloca_cinema, aloca_cliente, cadastra_cinema, cadastra_cliente, busca_cinema e mostra_cinema
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct cinema {
	int regsala;
	char filme[80];
	int ingressos;
	float valor;
}cinema;

typedef struct cliente {
	char CPF[13];
	char nome[80];
	int numsala;
	int qtdeingressos;
}cliente;

void aloca_cinema(cinema **p, int tam);
void aloca_cliente(cliente **p, int tam);
void cadastra_cinema(cinema *p, int tam);
void cadastra_cliente(cliente *p, cinema *q);
void mostra_cinema(cinema *p, int tam);
int busca_cinema(cinema *p, char *fil, int qtd);
void mostra_cliente(cliente *p, int tam);
void desistencia(cliente *p, cinema *q, int tam);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int op, cont=0;
	cliente *cli=NULL;
	cinema *cin=NULL;
	
	aloca_cinema(&cin, 3);
	cadastra_cinema(cin, 3);
	
	do
	{
		system("cls");
		printf("[1] Cadastro\n");
		printf("[2] Desistência\n");
		printf("[3] Fim\n");
		printf("\nOpção: ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1:
				{
					system("cls");
					mostra_cinema(cin, 3);
					aloca_cliente(&cli, cont+1);
					cadastra_cliente(cli+cont, cin);
					cont++;
					break;
				}
			case 2:
				{
					system("cls");
					mostra_cliente(cli, cont);
					desistencia(cli, cin, cont);
					break;
				}
			case 3:
				{
					continue;
				}
		}
	}while (op != 3);
	
	return 0;
}

void aloca_cinema(cinema **p, int tam)
{
	*p = (cinema*) realloc(*p, tam*sizeof(cinema));
	
	if(*p == NULL)
		exit(1);	
}

void aloca_cliente(cliente **p, int tam)
{
	*p = (cliente*) realloc(*p, tam*sizeof(cliente));
	
	if(*p == NULL)
		exit(1);
}

void cadastra_cinema(cinema *p, int tam)
{
	int i;
	
	for(i=0; i<tam; i++, p++)
	{
		fflush(stdin);
		p->regsala = i+1;
		p->ingressos = 20;
		printf("\nNome do filme da sala %d: ", i+1);
		gets(p->filme);
		printf("Valor unitário do ingresso: ");
		scanf("%f", &p->valor);	
	}	
}

void mostra_cinema(cinema *p, int tam)
{
	int i;
	
	for(i=0; i<tam; i++, p++)
	{
		printf("\nSala %d\n", p->regsala);
		printf("Filme: %s\n", p->filme);
		printf("Quantidade de ingressos disponíveis: %d\n", p->ingressos);
		printf("Valor unitário do ingresso: %.2f\n", p->valor);
	}
}

void cadastra_cliente(cliente *p, cinema *q)
{
	char aux_filme[80];
	int aux_sala, aux_ing;
	
	fflush(stdin);
	printf("\nNome do filme: ");
	gets(aux_filme);
	
	printf("Quantidade de ingressos: ");
	scanf("%d", &aux_ing);
	
	aux_sala = busca_cinema(q, aux_filme, aux_ing);
	
	if(aux_sala == -1)
	{
		printf("\nFilme indisponível\n\n");
		p->numsala = -1;
		system("pause");
	}
	else
	{
		printf("\nFilme disponível !\n");
		p->numsala = aux_sala;
		fflush(stdin);
		p->qtdeingressos = aux_ing;
		printf("\nNome do cliente: ");
		gets(p->nome);
		fflush(stdin);
		printf("CPF do cliente: ");
		gets(p->CPF);
		
		printf("\nNome: %s\n", p->nome);
		printf("CPF: %s\n", p->CPF);
		printf("Sala: %d\n", p->numsala);
		printf("Quantidade de ingressos reservados: %d\n", p->qtdeingressos);
		printf("Total a pagar: %.2f\n", p->qtdeingressos*(q+p->numsala-1)->valor);
		
		printf("\nCadastro realizado !\n\n");
		system("pause");
	}
}

int busca_cinema(cinema *p, char *fil, int qtd)
{
	int i;
	
	for(i=0; i<3; i++, p++)
	{
		if(!strcmp(p->filme, fil) && qtd <= p->ingressos)
		{
			p->ingressos = p->ingressos - qtd;
			return p->regsala;
		}
	}
	
	return -1;
}

void mostra_cliente(cliente *p, int tam)
{
	int i;
	
	for(i=0; i<tam; i++, p++)
	{
		if(p->numsala != -1)
		{
			printf("\nNome: %s\n", p->nome);
			printf("CPF: %s\n", p->CPF);
			printf("Sala: %d\n", p->numsala);
			printf("Quantidade de ingressos reservados: %d\n", p->qtdeingressos);
		}
	}
	
	printf("\n");
	system("pause");
}

void desistencia(cliente *p, cinema *q, int tam)
{
	char aux_cpf[13];
	int i, achou=0;
	
	fflush(stdin);
	printf("\nCPF do cliente desistente: ");
	gets(aux_cpf);
	
	for(i=0; i<tam; i++, p++)
	{
		if(!strcmp(p->CPF, aux_cpf))
		{
			achou = 1;
			printf("\nNome: %s\n", p->nome);
			printf("CPF: %s\n", p->CPF);
			printf("Sala: %d\n", p->numsala);
			printf("Filme: %s\n", (q+p->numsala-1)->filme);
			printf("Quantidade de ingressos reservados: %d\n", p->qtdeingressos);
			printf("Valor de reembolso: %.2f\n", p->qtdeingressos*(q+p->numsala-1)->valor);
			(q+p->numsala-1)->ingressos = (q+p->numsala-1)->ingressos + p->qtdeingressos;
			p->numsala = -1;
			printf("\nDesistência realizada\n\n");
			system("pause");
		}
	}
	
	if(achou == 0)
	{
		printf("\nCliente não encontrado\n\n");
		system("pause");
	}
}

/*
Fazer um programa de Sistema de Reserva de Ingressos para Shows. Alocar dinamicamente
espaço e cadastrar 3 shows, iniciar a quantidade de ingressos com 50. Em seguida, fazer o menu
para:
[1] Reserva – mostrar todas as informações da struct show. Em seguida, alocar dinamicamente
espaço para 1 cliente, receber o CPF, nome do cliente, o nome do show e a quantidade de ingressos
desejados. Buscar o número do show, de acordo com o nome da atração e quantidade de
ingressos disponíveis. Apresentar o número do show e o valor total a ser pago pelo cliente e não
esquecer de:
? na estrutura cliente: guardar o número do show e a quantidade de ingressos
? na estrutura show: atualizar a quantidade de ingressos (subtrair)
[2] Desistência – encerra a reserva pelo CPF do cliente. Mostrar o nome do cliente, o nome da
atração, a quantidade de ingressos que haviam sido reservados e o valor total a ser devolvido para
o cliente. Não esquecer de:
? na estrutura cliente: mudar o número do show para -1
? na estrutura show: acrescer a quantidade de ingressos devolvidos ao total disponível
[3] Fim

typedef struct show{
int regshow; //registro do show – gerado automaticamente
char atracao[40]; //nome da atração
int ingressos; //quantidade de ingressos disponíveis
float valor; //valor de cada ingresso
}show;

typedef struct cliente{
char CPF[13]; //CPF do cliente
char nome[80]; //nome do cliente
int numshow; //número do registro do show
int qtdeingressos; //quantidade de ingressos reservados
}cliente;

Utilizar ponteiro para show e ponteiro para cliente e fazer as funções:
aloca_show, aloca_cliente, cadastra_show, cadastra_cliente, busca_show e mostra_show
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct show{
	int regshow; 
	char atracao[40]; 
	int ingressos; 
	float valor; 
}show;

typedef struct cliente{
	char CPF[13]; 
	char nome[80]; 
	int numshow; 
	int qtdeingressos; 
}cliente;

void aloca_show(show **p, int tam);
void aloca_cliente(cliente **p, int tam);
void cadastra_show(show *p, int tam);
void cadastra_cliente(cliente *p, show *q);
void mostra_show(show *p, int tam);
int busca_show(show *p, char *atr, int qtd);
void mostra_cliente(cliente *p, int tam);
void desistencia(cliente *p, show *q, int tam);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int op, cont=0;
	cliente *cli=NULL;
	show *sho=NULL;
	
	aloca_show(&sho, 3);
	cadastra_show(sho, 3);
	
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
					mostra_show(sho, 3);
					aloca_cliente(&cli, cont+1);
					cadastra_cliente(cli+cont, sho);
					cont++;
					break;
				}
			case 2:
				{
					system("cls");
					mostra_cliente(cli, cont);
					desistencia(cli, sho, cont);
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

void aloca_show(show **p, int tam)
{
	*p = (show*) realloc(*p, tam*sizeof(show));
	
	if(*p == NULL)
		exit(1);	
}

void aloca_cliente(cliente **p, int tam)
{
	*p = (cliente*) realloc(*p, tam*sizeof(cliente));
	
	if(*p == NULL)
		exit(1);
}

void cadastra_show(show *p, int tam)
{
	int i;
	
	for(i=0; i<tam; i++, p++)
	{
		fflush(stdin);
		p->regshow = i+1;
		p->ingressos = 50;
		printf("\nNome da atração do palco %d: ", i+1);
		gets(p->atracao);
		printf("Valor unitário do ingresso: ");
		scanf("%f", &p->valor);	
	}	
}

void mostra_show(show *p, int tam)
{
	int i;
	
	for(i=0; i<tam; i++, p++)
	{
		printf("\nPalco %d\n", p->regshow);
		printf("Show: %s\n", p->atracao);
		printf("Quantidade de ingressos disponíveis: %d\n", p->ingressos);
		printf("Valor unitário do ingresso: %.2f\n", p->valor);
	}
}

void cadastra_cliente(cliente *p, show *q)
{
	char aux_show[80];
	int aux_palco, aux_ing;
	
	fflush(stdin);
	printf("\nNome do show: ");
	gets(aux_show);
	
	printf("Quantidade de ingressos: ");
	scanf("%d", &aux_ing);
	
	aux_palco = busca_show(q, aux_show, aux_ing);
	
	if(aux_palco == -1)
	{
		printf("\nShow indisponível\n\n");
		p->numshow = -1;
		system("pause");
	}
	else
	{
		printf("\nShow disponível !\n");
		p->numshow = aux_palco;
		fflush(stdin);
		p->qtdeingressos = aux_ing;
		printf("\nNome do cliente: ");
		gets(p->nome);
		fflush(stdin);
		printf("CPF do cliente: ");
		gets(p->CPF);
		
		printf("\nNome: %s\n", p->nome);
		printf("CPF: %s\n", p->CPF);
		printf("Palco: %d\n", p->numshow);
		printf("Quantidade de ingressos reservados: %d\n", p->qtdeingressos);
		printf("Total a pagar: %.2f\n", p->qtdeingressos*(q+p->numshow-1)->valor);
		
		printf("\nCadastro realizado !\n\n");
		system("pause");
	}
}

int busca_show(show *p, char *fil, int qtd)
{
	int i;
	
	for(i=0; i<3; i++, p++)
	{
		if(!strcmp(p->atracao, fil) && qtd <= p->ingressos)
		{
			p->ingressos = p->ingressos - qtd;
			return p->regshow;
		}
	}
	
	return -1;
}

void mostra_cliente(cliente *p, int tam)
{
	int i;
	
	for(i=0; i<tam; i++, p++)
	{
		if(p->numshow != -1)
		{
			printf("\nNome: %s\n", p->nome);
			printf("CPF: %s\n", p->CPF);
			printf("Palco: %d\n", p->numshow);
			printf("Quantidade de ingressos reservados: %d\n", p->qtdeingressos);
		}
	}
	
	printf("\n");
	system("pause");
}

void desistencia(cliente *p, show *q, int tam)
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
			printf("Palco: %d\n", p->numshow);
			printf("Atração: %s\n", (q+p->numshow-1)->atracao);
			printf("Quantidade de ingressos reservados: %d\n", p->qtdeingressos);
			printf("Valor de reembolso: %.2f\n", p->qtdeingressos*(q+p->numshow-1)->valor);
			(q+p->numshow-1)->ingressos = (q+p->numshow-1)->ingressos + p->qtdeingressos;
			p->numshow = -1;
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

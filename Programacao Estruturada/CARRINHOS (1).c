#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct carro {
	int reg_carro;
	char tipo;
	char status;
}carro;

typedef struct cliente {
	char CPF[13];
	char nome[80];
	int num_reg;
	int dias;
}cliente;

void aloca_carro(carro **p, int tam);
void cadastra_carro(carro *p, int tam);
void mostra_carro(carro *p, int tam);
void aloca_cliente(cliente **p, int tam);
void cadastra_cliente(cliente *p, carro *q);
int busca_carro(carro *p, char type);
void devolucao(carro *p, cliente *q, int tam);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	cliente *cli=NULL;
	carro *car=NULL;
	int op, cont=0;
	
	aloca_carro(&car, 15);
	cadastra_carro(car, 15);
	
	do
	{
		system("cls");
		printf("\n[1] Locação\n");
		printf("[2] Devolução\n");
		printf("[3] Fim\n");
		printf("\nOpção: ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1:
			{
				system("cls");
				mostra_carro(car, 15);
				aloca_cliente(&cli, cont+1);
				cadastra_cliente(cli+cont, car);
				cont++;
				break;
			}
			case 2:
			{
				system("cls");
				devolucao(car, cli, cont);
				break;
			}
			case 3:
			{
				continue;
			}
		}
	}while(op != 3);
	
	return 0;
}

void aloca_carro(carro **p, int tam)
{
	*p = (carro*) realloc(*p, tam*sizeof(carro));
	
	if(*p == NULL)
		exit(1);
}

void aloca_cliente(cliente **p, int tam)
{
	*p = (cliente*) realloc(*p, tam*sizeof(cliente));
	
	if(*p == NULL)
		exit(1);
}

void cadastra_carro(carro *p, int tam)
{
	int i;
	
	for(i=0; i<tam; i++, p++)
	{
		if(i<5)
		{
			p->reg_carro = i+1;
			p->tipo = 'P';
			p->status = 'L';
		}
		else if(i >= 5 && i<10)
		{
			p->reg_carro = i+1;
			p->tipo = 'M';
			p->status = 'L';
		}
		else if(i >= 10 && i<15)
		{
			p->reg_carro = i+1;
			p->tipo = 'G';
			p->status = 'L';
		}
	}
}

void mostra_carro(carro *p, int tam)
{
	int i;
	
	for(i=0; i<tam; i++, p++)
	{
		printf("\nCarro %d\n", p->reg_carro);
		printf("Tipo: %c\n", p->tipo);
		printf("Status: %c\n", p->status);
	}
}

void cadastra_cliente(cliente *p, carro *q)
{
	char aux_tipo;
	int aux_regcarro;
	
	fflush(stdin);
	printf("\nTipo de carro desejado (P/M/G): ");
	scanf("%c", &aux_tipo);
	
	aux_regcarro = busca_carro(q, aux_tipo);
	
	if(aux_regcarro == -1)
	{
		printf("\nNão há carro do tipo %c disponível\n\n", aux_tipo);
		system("pause");
	}
	else
	{
		p->num_reg = aux_regcarro;
		printf("\nCarro disponível\n");
		fflush(stdin);
		printf("\nNome do cliente: ");
		gets(p->nome);
		fflush(stdin);
		printf("CPF do cliente: ");
		gets(p->CPF);
		printf("Quantidade de dias de aluguel: ");
		scanf("%d", &p->dias);
		
		printf("\nLocação realizada\n\n");
		system("pause");
	}
	
}

int busca_carro(carro *p, char type)
{
	int i;
	
	for(i=0; i<15; i++, p++)
	{
		if(p->tipo == type && p->status == 'L')
		{
			p->status = 'A';
			return p->reg_carro;
		}
	}
	
	return -1;
}

void devolucao(carro *p, cliente *q, int tam)
{
	char aux_cpf[13];
	int i, achou=0;
	
	fflush(stdin);
	printf("\nCPF do cliente desistente: ");
	gets(aux_cpf);
	
	for(i=0; i<tam; i++, q++)
	{
		if(!strcmp(aux_cpf, q->CPF))
		{
			achou = 1;
			printf("\nNome do cliente: %s\n", q->nome);
			printf("CPF do cliente: %s\n", q->CPF);
			printf("Número de registro: %d\n", q->num_reg);
			printf("Quantidade de dias de aluguel: %d\n\n", q->dias);
			(p+q->num_reg-1)->status = 'L';
			system("pause");	
		}
	}
	
	if(achou == 0)
	{
		printf("\nCPF não encontrado\n\n");	
		system("pause");
	}
}

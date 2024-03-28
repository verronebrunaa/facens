#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aloca(char **p, int tam); 
void maiuscula(char *p, int tam); 
int busca_nome(char *p, int tam, char letra, char **pl);

main(){

char *ptr=NULL, aux[20], op, letra, *pletra=NULL;
int cont=0, tam=0, cnome;

do{
    printf("\n Digite o nome: ");
    gets(aux);
    fflush(stdin);
    tam=strlen(aux)+1; //por conta do '\0'
    aloca(&ptr, tam); //ponteiro > ponteiro
    if(cont==0)
    strcpy(ptr, aux)
    else{
        strcat(ptr, "\n")
        strcat
    }
    strcpy(ptr, aux);
    cont++;
    printf("Deseja continuar <S/N>:");
    scanf("%c", &op);
    fflush(stdin);
}while(op!='n'&&op!='N');

printf("\n Foram alocados %i nomes: \n%s\n\n", cont, ptr);
printf("\n Digite a letra a ser procurada: ");
fflush(stdin);
maiuscula(&letra,1);
cnome=busca_nome(ptr, tam, letra, &pletra);

if(cnome!=0)
    printf("tivemos %i nomes comecados com a letra: %c\n%s\n\n", cnome, letra, pletra);
else("Nao tivemos nome comecados com a letra: %c\n\n", letra);
system("pause");
}

void aloca(char **p, int tam){
    if((*p=(char*)realloc(*p, tam*sizeof(char)))==NULL) 
    exit(1);
}

void maiuscula(char *p, int tam){
    int i;
    for(i=0;i<tam; i++,p++)
    if(*p>='a'&&*p<='z')
    *p-=32;
}

int busca_nome(char *´, int tam, char letra, char **pl){
int i, cont=0 qnome=0;

for(i=0; i<tam;i++)
    if((i==0 &&*(p+i)==letra)||(*(p+i)=='\n'&&*(p+i+1)==letra)){
        qnome++;
        do{
            aloca(pl, cont+1);
            *(*pl+cont)=*(p+i);
            cont++;
            i++;
        }while(*(p=i)!='\n');
        i--; //para voltar no \n
    }
     aloca(pl, cont+1);
     *(*pl+cont)='\0';
     return qnome;
}
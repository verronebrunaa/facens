#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aloca(char **p, int tam);

main(){

char *ptr=NULL, aux[20], op;
int cont=0, tam;

do{
    printf("\n Digite o nome: ");
    gets(aux);
    fflush(stdin);
    tam=strlen(aux)+1; //por conta do '\0'
    aloca(&ptr, tam); //ponteiro > ponteiro
}while

}
void aloca(char **p, int tam){
    if((*p=(char*)realloc(*p, tam*sizeof(char)))==NULL) 
    exit(1);
}
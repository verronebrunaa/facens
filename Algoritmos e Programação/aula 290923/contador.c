#include <stdio.h>

int main(){
    int cont, resp, sim=0, nao=0;

printf("Olá! Esse programa conta quantas pessoas torcem para o Flamengo e quantas não torcem.\n");
    for(cont=1; cont<=8; cont++){
        printf("Digite 1 para sim e 2 para não: ");
        scanf("%i", &resp);
        if(resp==1){
            sim++;
        }
        else if(resp==2){
            nao++;
        }
        else{
            printf("Resposta inválida, digite novamente.\n");
            cont--;
        }
    }
    printf("A quantidade de pessoas que torcem para o Flamengo é %i\n", sim);
    printf("A quantidade de pessoas que não torcem para o Flamengo é %i\n", nao);

    
}
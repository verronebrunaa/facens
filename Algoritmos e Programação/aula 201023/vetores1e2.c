/*
Receber 10 números e armazená-los em um vetor. 
Ao final, exibir os números na ordem crescente e decrescente em que foram digitados.
*/ 

#include <stdio.h>

int main(){
    int i, vetor[10];

    for(i = 0; i < 10; i++){
        printf("Digite o %iº número: ", i+1); //receba 10 números e armazene-os em um vetor
        scanf("%i", &vetor[i]);
    }

    for(i = 0; i < 10; i++){
        printf("Ordem crescente: | %i |\n ", vetor[i]); //exiba os números na ordem que foram digitados
    }
    printf("\n");
    for(i = 9; i >= 0; i--){
        printf("Ordem decrescente: | %i |\n", vetor[i]); //exiba os números na ordem inversa que foram digitados
    }
    
}
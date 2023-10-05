#include <stdio.h> 

int main(){
    int i, n;
    printf("Olá, eu sou um programa que calcula a tabuada de um número inteiro.\n");
    printf("Digite um numero: ");
    scanf("%i", &n);
    for(i=1; i<=10; i++){
        printf("%i x %i = %i\n", n, i, n*i);
    } 
}
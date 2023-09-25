#include <stdio.h>

int main(){
    //Criar um programa em Linguagem C que receba dois números inteiros e retorne: o valor da divisão e o resto da divisão.
    int numero1, numero2, divisao, resto;
    printf("Insira o primeiro e o segundo número: ", numero1, numero2);
    scanf("%i %i", &numero1, &numero2);
    divisao = numero1 / numero2;
    resto = numero1 % numero2;
    printf("A divisão de %i por %i é %i e o resto é %i", numero1, numero2, divisao, resto);
}
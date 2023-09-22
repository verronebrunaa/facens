#include <stdio.h>

int main(){
    //Receber um número, calcular seu dobro e exibir o resultado.
    int numero, dobro;
    printf("Insira um número: ", numero);
    scanf("%i", &numero);
    dobro = numero * 2;
    printf("O dobro de %i é %i", numero, dobro);
}
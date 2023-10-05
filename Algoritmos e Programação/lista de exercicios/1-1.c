#include <stdio.h>

int main(){
    //Receber um número, calcular seu dobro e exibir o resultado.
    int numero, dobro;
    printf("Insira um número: ", numero);
    scanf("%i", &numero); //Scanf é uma função que recebe um valor/dado do usuário e armazena na variável 'valor'
    dobro = numero * 2;
    printf("O dobro de %i é %i", numero, dobro);
}
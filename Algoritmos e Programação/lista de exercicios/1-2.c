#include <stdio.h>

int main(){
    //Receber dois valores, calcular sua média aritmética e exibir o resultado.

    int numero1, numero2, media;
    printf("Insira o primeiro e o segundo número: ", numero1, numero2);
    scanf("%i %i", &numero1, &numero2);
    media = (numero1 + numero2) / 2;
    printf("A média aritmética de %i e %i é %i", numero1, numero2, media);
}
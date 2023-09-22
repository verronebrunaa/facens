#include <studio.h>

int main(){
    //Receber dois valores, calcular sua média aritmética e exibir o resultado.

    int num1, num2, media;
    printf("Insira o primeiro número: ", num1);
    scanf("%i", &num1);
    printf("Insira o segundo número: ", num2);
    scanf("%i", &num2);
    media = (num1 + num2) / 2;
    printf("A média aritmética de %i e %i é %i", num1, num2, media);
}
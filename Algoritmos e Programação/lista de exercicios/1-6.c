#include <stdio.h>

int main(){
    //Receber base e altura de um triângulo, calcular sua área e exibir o valor calculado.
    int base, altura, area;
    printf("Insira a base e a altura do triângulo: ", base, altura);
    scanf("%i %i", &base, &altura);
    area = (base * altura) / 2;
    printf("A área do triângulo é %i", area);
}
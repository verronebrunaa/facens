#include <stdio.h>

int main(){
    //Receber uma temperatura em Fahrenheit e convertê-la para Celsius através da seguinte fórmula: Celsius = (Fahrenheit - 32) / 1.8. Exibir o valor em Celsius.
    
    float fahrenheit, celsius;

    printf("Digite a temperatura em Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32) / 1.8;
    printf("A temperatura digitada e convertida para Celsius é: %0.2f\n", celsius);
}

#include <stdio.h>

int main()
{
    float num1, num2, media;
    char op;

    do
    {
        printf("Digite o primeiro número: ");
        scanf("%f", &num1);
        printf("Digite o segundo número: ");
        scanf("%f", &num2);

        media = (num1 + num2) / 2.0f;
        printf("A média de %.2f e %.2f é: %.2f\n", num1, num2, media);
        
        printf("Gostaria de calcular outra média? (s/n) ");
        fflush(stdin); // Limpa o buffer do teclado para evitar que o scanf leia o \n do enter como uma entrada.
        scanf(" %c", &op);

    } while (op == 's' || op == 'S');
    
}
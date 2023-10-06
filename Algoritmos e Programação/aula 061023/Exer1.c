#include <stdio.h>

int main()
{
    /* receber a nota de um aluno no modulo 1 e no modulo 2 e calcular a media final. Só serão aceitas notas entre 0 e 10. caso o usuario digite uma nota inválida, o programa deve pedir para que ele digite novamente.*/

    float nota1, nota2, media;

    do
    {
        printf("Digite a nota do modulo 1: ");
        fflush(stdin);
        scanf("%f", &nota1);

        if (nota1 < 0 || nota1 > 10)
            printf("Nota do Modulo 1 inválida, digite novamente.\n");

    } while (nota1 < 0 || nota1 > 10);

    do
    {
        printf("Digite a nota do modulo 2: ");
        fflush(stdin);
        scanf("%f", &nota1);
        
        if (nota2 < 0 || nota2 > 10)
            printf("Nota do Modulo 1 inválida, digite novamente.\n");
    } while (nota1 < 0 || nota1 > 10);

    media = (nota1 + nota2) / 2.0f;
    printf("A média final é: %.2f\n", media);
}
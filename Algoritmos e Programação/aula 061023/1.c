#include <stdio.h>

int main()
{
    /* receber a nota de um aluno no modulo 1 e no modulo 2 e calcular a media final.
    só sao aceitas notas entre 0 e 10. caso o usuario digite uma nota invalida, o programa deve pedir para que ele digite novamente.*/
    float nota1, nota2, media;

    do
    {
        printf("Digite a nota do modulo 1: ");
        fflush(stdin);
        scanf("%f", &nota1);

    } while (nota1 < 0 || nota1 > 10);

    do
    {
        printf("Digite a nota do modulo 1: ");
        fflush(stdin);
        scanf("%f", &nota1);

    } while (nota1 < 0 || nota1 > 10);

    media = (nota1 + nota2) / 2.0f;
    printf("A média final é: %.2f\n", media);
}
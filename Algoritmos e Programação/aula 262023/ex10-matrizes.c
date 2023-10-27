 /*Faça um programa que recebe uma matriz 3x4 e mostra
▪ soma dos seus elementos
▪ soma de cada linha da matriz.
▪ soma de cada coluna da matriz
*/

#include <stdio.h>
#define L 3
#define C 4

int main(){
    int i, j;
    int matriz[L][C] = {
        01, 02, 0, -4,
        06, 01, 10, 02,
        07, 03, 17, -2};
    int soma = 0;
    printf("|---------------------------------|\n");
    printf("|            Matriz %dx%d           |\n", L, C);
    printf("|---------------------------------|\n");
    for (i = 0; i < L; i++)
    {
        for (j = 0; j < C; j++)
        {
            printf("| %3d  | ", matriz[i][j]);
            soma += matriz[i][j];
        }
        printf("\n");
    }
    printf("|---------------------------------|\n");
    printf("|     Soma dos elementos: %d      |\n", soma);
    printf("|---------------------------------|\n");
    printf("|      Soma de cada linha:        |\n");
    for (i = 0; i < L; i++)
    {
        soma = 0;
        for (j = 0; j < C; j++)
        {
            soma += matriz[i][j];
        }
        printf("|    Linha %d:   |        %d       |\n", i+1, soma);
    }
    printf("|---------------------------------|\n");
    printf("|         Soma de cada coluna:    |\n");
    for (j = 0; j < C; j++)
    {
        soma = 0;
        for (i = 0; i < L; i++)
        {
            soma += matriz[i][j];
        }
        printf("|    Coluna %d:   |      %3d       |\n", j+1, soma);
    }
    printf("|---------------------------------|\n");
    return 0;
}
/*Inserir números aleatórios em uma matriz bidimensional 4x5. 
E mostrá-los na tela em forma de tabela.*/

#include <stdio.h>
#define L 4
#define C 5

int main()
{
    int i, j;
    int matriz[L][C] = {
        1, 2, 0, -4, 3,
        6, 1, 10, 2, 3,
        7, 3, 17, -2, 61,
        0, -3, 1, -22, 6};
    printf("|------------------------------------------|\n");
    printf("|               Matriz %dx%d                 |\n", L, C);
    printf("|------------------------------------------|\n");
    for (i = 0; i < L; i++)
    {
        for (j = 0; j < C; j++)
        {
            printf("| %3d  | ", matriz[i][j]);
        }
        printf("\n");
    }
        printf("|------------------------------------------|\n");

    return 0;
}
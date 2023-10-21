#include <stdio.h>

int main(){
int matriz[3][3], linha, coluna;

    for(linha=0; linha < 3; linha++){
        for(coluna=0; coluna < 4; coluna++){
            printf("Digite o valor da linha %i e coluna %i: ", linha+1, coluna+1);
            scanf("%i", &matriz[linha][coluna]);
        }
    }

    for(linha=0; linha < 3; linha++){
        for(coluna=0; coluna < 4; coluna++){
            printf("| Valor linha %i e coluna %i = %i ", linha, coluna,  matriz[linha][coluna]);
        }
        printf("\n");
    }
}
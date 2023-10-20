/*  Receber 8 números e armazená-los em um vetor.
Ao final, pedir para o usuário escolher uma posição do vetor e exibir o número que está armazenado nesta posição. */

#include <stdio.h>

int main()
{
    int i, posicaoEscolhida;
    float vetor[8];

    for (i = 0, i < 8, i++){
        printf("Digite o %iº número: ", i + 1);
        scanf("%f", &vetor[i]);
    }

    printf("Escolha um número que foi digitado: ");
    scanf("%i", &posicaoEscolhida);
    printf("Valor escolhido %.2f \n", vetor[posicaoEscolhida - 1]);
}
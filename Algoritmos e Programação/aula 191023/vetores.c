#include <stdio.h>

int main()
{
    int i;
    int idade[10];

    float media, soma;

    for(i = 0; i < 10; i++){
        printf("Digite a idade da pessoa %i: ", i+1);
        scanf("%d", &idade[i]);
        soma += (float)idade[i];
    }
    
    float media = soma / 10.0f;
    printf("A média das idades é %0.2f\n", media);
    printf("A quinta idade é %i\n", idade[4]);

    return 0;
}
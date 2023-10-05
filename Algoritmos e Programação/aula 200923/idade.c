#include <stdio.h>

int main(){
    //Receber idade de 8 pessoas ao final exibir a soma total das idades e quantos tem 18 anos ou mais.

    int i, idade, soma = 0, qtd = 0;
    for(i = 0; i < 8; i++){
        printf("Insira a idade da pessoa %i: ", i + 1);
        scanf("%i", &idade);
        soma = soma + idade;
        if(idade >= 18){
            qtd++;
        }
    }
    printf("A soma das idades é %i\n", soma);
    printf("A quantidade de pessoas com 18 anos ou mais é %i\n", qtd);
}
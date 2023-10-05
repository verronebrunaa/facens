#include <stdio.h>

int main(){
    //receba as idades de 8 pessoas e mostre quantas são maiores de idade e quantas são menores de idade.

    // int idade, cont, maior18=0, menor=0;
    // for(cont=1; cont<=8; cont++){
    //     printf("%i Digite a sua idade: ", cont);

    //     cont = cont + idade;

    //     if(idade>=18){
    //         maior18++;
    //     }else{
    //         menor++;
    //     }
    //     printf("Maior de idade: %i\n", maior18);
    //     printf("Menor de idade: %i\n", menor);
    //     printf("Total de pessoas: %i\n", cont);

    int idade, mais18=0, soma=0
        for (i = 1; i <= 8; i++){
            printf("Digite a idade: ");
            scanf("%i", &idade);
            
            soma = soma + idade;
            if(idade >= 18){
                mais18++;
            }
            else
            {
                menor++;
            }   
        }
 }

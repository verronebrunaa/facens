/* Criar um programa de calculadora que vai realizando os calculos entre dois numeors enquanto o usuario desejar.Criar um menu de opcoes para o usuario escolher qual operacao deseja realizar.*/ 

#include <stdio.h>

int main(){
    int num1, num2, opcao, soma, subtracao, multiplicacao, divisao;
    char op;
    do{
        printf("Calculadora\n");
        
        printf("|-----------------------|\n");
        printf("|  Escolha uma opção:   |\n");
        printf("|   1 - Soma            |\n");
        printf("|   2 - Subtração       |\n");
        printf("|   3 - Multiplicação   |\n");
        printf("|   4 - Divisão         |\n");
        printf("|   5 - Sair            |\n");
        printf("|-----------------------|\n");
        fflush(stdin);
        scanf("%i", &opcao);

        printf("Digite o primeiro número: ");
        scanf("%i", &num1);
        printf("Digite o segundo número: ");
        scanf("%i", &num2);

        switch(opcao){
            case 1:
                soma = num1 + num2;
                printf("A soma de %i e %i é %i\n", num1, num2, soma);
                break;
            case 2:
                subtracao = num1 - num2;
                printf("A subtração de %i e %i é %i\n", num1, num2, subtracao);
                break;
            case 3:
                multiplicacao = num1 * num2;
                printf("A multiplicação de %i e %i é %i\n", num1, num2, multiplicacao);
                break;
            case 4:
                divisao = num1 / num2;
                printf("A divisão de %i e %i é %i\n", num1, num2, divisao);
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
        printf("Deseja realizar outra operação? (s/n) ");
        fflush(stdin);
        scanf(" %c", &op);
    }while(op == 's' || op == 'S');
}
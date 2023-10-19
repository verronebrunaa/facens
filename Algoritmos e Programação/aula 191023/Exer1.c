/*  Receber 10 números e armazená-los em um vetor.
    Após esta primeira etapa é necessário pedir para o usuário digitar um número. Verificar se este
número está armazenado no vetor e se estiver, mostrar quantas vezes o número esta armazenado no
vetor, ou seja, quantas vezes o número se repete. Se o número não estiver no vetor, uma mensagem
deve indicar esta condição e deverá ser solicitado um novo número para o usuário.*/

#include <stdio.h>

int main(){
    int i, num[10], numero, cont = 0;

    for(i = 0; i < 10; i++){
        printf("Digite o %iº número: ", i+1);
        scanf("%i", &num[i]);
    }

    printf("Digite um número: ");
    scanf("%i", &numero);

    for(i = 0; i < 10; i++){
       if (cont > 0){
        printf("O número %i aparece %i vezes no vetor\n", numero, cont);
    } else
    {
        printf("O número %i não aparece no vetor\n", numero);
        printf("Por favor, digite um novo número: ");
        scanf("%i", &numero);
        for(i = 0; i < 10; i++){
            if(numero == num[i]){
                cont++;
            }
        }
    }
    } 
    
    
}
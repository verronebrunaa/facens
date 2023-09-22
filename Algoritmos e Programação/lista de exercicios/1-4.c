#include <stdio.h>

int main(){
    //Receber o ano de nascimento de uma pessoa e mostrar aproximadamente quantos dias de vida ela tem.
    int anoDeNascimento, idade, diasDeVida, anoAtual=2023, ano=365;
    printf("Insira o seu ano de nascimento: ", anoDeNascimento);
    scanf("%i", &anoDeNascimento); 

    idade = anoAtual - anoDeNascimento;
    diasDeVida = idade * ano;
    printf("Você tem aproximadamente %i dias de vida", diasDeVida);
}
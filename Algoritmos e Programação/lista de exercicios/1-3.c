#include <stdio.h>

int main(){
   //Receber um comprimento em metros, convertê-lo para centímetros e mostrar o resultado.
   float metros, centimetros;
    printf("Insira um comprimento em metros: ", metros);
    scanf("%f", &metros); 
    centimetros = metros * 100;
    printf("O comprimento inserido em metros se torna %.2f centímetros.", centimetros);
}
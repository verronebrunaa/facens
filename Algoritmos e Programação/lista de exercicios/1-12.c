#include <stdio.h>

int main(){
    /*.Uma empresa paga R$ 10.00 por hora normal trabalhada e R$ 15.00 por
    hora extra. Receber o total de horas normais e o total de horas extras
    trabalhadas por um empregado no mês. Calcular e exibir o salário dele.*/
    int horasNormais, horasExtras;
    float salario, horasTrabalhadas;
     printf("Insira o número total de horas normais trabalhadas por dia: ", horasNormais);
    scanf("%i", &horasNormais);
    printf("Insira o número total de horas extras trabalhadas no mês: ", horasExtras);
    scanf("%i", &horasExtras);
    horasTrabalhadas = horasNormais * 22;
    salario = (horasTrabalhadas * 10) + (horasExtras * 15);
    printf("O salário do funcionário é R$%.2f", salario);
}
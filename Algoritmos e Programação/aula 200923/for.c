#include <stdio.h>

main()
{
  int i;
  float num, soma = 0;

  for(i=1; i<=5; i++)
  {
    printf("Digite o %iº número: ", i);
    scanf("%f", &num);
    soma = soma + num;
  }
  printf("A soma dos números é: %.2f", soma);
}
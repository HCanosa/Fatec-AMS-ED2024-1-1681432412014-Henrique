#include <stdio.h>

void calc(int *preco,int *desconto,float *valorfinal){

  *valorfinal = *preco - (*preco * *desconto/100.0);
}

int preco;
int desconto;
float valorfinal;

int main(void) {
  
  printf("digite o preço: \n");
  scanf("%d", &preco);

  printf("digite o desconto em porcentagem: \n");
  scanf("%d", &desconto);

  calc(&preco, &desconto, &valorfinal);

  printf("preco %d\n deconto aplicado: %d%%\n  e valor final: %.2f", preco,desconto, valorfinal);

  return 0;
}
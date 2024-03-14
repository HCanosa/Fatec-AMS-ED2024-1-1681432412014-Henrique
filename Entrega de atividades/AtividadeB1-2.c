#include <stdio.h>

void calc(int *preco,int *desconto,float *resultado){

  *resultado = *preco - (*preco * *desconto/100.0);
}

int preco;
int desconto;
float resultado;

int main(void) {
  
  printf("digite o preço: \n");
  scanf("%d", &preco);

  printf("digite o desconto em porcentagem: \n");
  scanf("%d", &desconto);

  calc(&preco, &desconto, &resultado);

  printf("preco %d\n deconto aplicado: %d%%\n  e valor final: %.2f", preco,desconto, resultado);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXTAM  20

typedef long CHAVE;
typedef struct ITEM_TAG {
  CHAVE chave;
  /* Outros componentes */
} ITEM;
typedef int INDICE;
typedef ITEM VETOR[MAXTAM];

void selecao(ITEM *a, int tam)
{
  INDICE i,j,min;
  ITEM x;
  
  for(i=0; i < tam-1; i++){
    min = i;
    for(j=i; j < tam; j++)
      if(a[j].chave < a[min].chave) min = j;
    x = a[min]; a[min] = a[i]; a[i] = x;
  }
}

double rand0a1()
{
  double res = (double)rand() / INT_MAX;
  if(res > 1.0) res = 1.0;
  return res;
}

void permuta(VETOR a, int tam)
{
  ITEM b;
  int i,j;
  
  for(i=tam-1; i>=0; i--){
    j = (i * rand0a1()) + 1;
    b = a[i];
    a[i] = a[j];
    a[j] = b;
  }
}

void imprime(VETOR a, int tam)
{
  int i;
  
  for(i=0; i<tam; i++) printf("%d ", a[i].chave);
  printf("\n");
}

int main(int argc, char *argv[])
{
  VETOR v;
  int n = sizeof(v)/sizeof(ITEM);
  int i;
  
  for(i=0; i<n; i++) v[i].chave = i;
  
  permuta(v,n);
  
  printf("Original\n");
  imprime(v,n);
  
  selecao(v,n);
  
  printf("Ordenado\n");
  imprime(v,n);
  
  return 0;
}

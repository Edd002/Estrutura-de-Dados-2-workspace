#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXTAM  200

typedef long CHAVE;
typedef struct ITEM_TAG {
  CHAVE chave;
  /* Outros componentes */
} ITEM;
typedef int INDICE;
typedef ITEM VETOR[MAXTAM];

void particao(INDICE esq, INDICE dir, INDICE *i, INDICE *j, ITEM *a)
{
  ITEM x,w;
  
  *i = esq; *j = dir;
  x = a[(*i + *j) / 2];  /*pivo*/
  do{
    while(x.chave > a[*i].chave) (*i)++;
    while(x.chave < a[*j].chave) (*j)--;
    if(*i <= *j) {
      w = a[*i]; a[*i] = a[*j]; a[*j] = w;
      (*i)++; (*j)--;
    }
  } while(*i <= *j);
}

void ordena(INDICE esq, INDICE dir, ITEM *a)
{
  INDICE i,j;
  
  particao(esq,dir,&i,&j,a);
  if(esq < j) ordena(esq,j,a);
  if(i < dir) ordena(i,dir,a);
}

void quicksort(ITEM *a, int tam)
{
  ordena(0,tam-1,a);
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
  
  quicksort(v,n);
  
  printf("Ordenado\n");
  imprime(v,n);
  
  system("PAUSE");	
  return 0;
}

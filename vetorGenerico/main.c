#include "vetor.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vetor {
  int tam_elem;
  int n;
  int capacidade;
  void *dados;
} Vetor;

Vetor *novo_vetor(int tam_elem) {
  Vetor *V = malloc(sizeof(Vetor));
  V->tam_elem = tam_elem;
  V->n = 0;
  V->capacidade = 1;
  V->dados = malloc(tam_elem);

  return V;
}
void finaliza_vetor(Vetor *V) {
  free(V->dados);
  free(V);
}

int tamanho_vetor(Vetor *V) { return V->n; }

void *elemento(Vetor *V, int index) {
  return (char *)(V->dados + index * V->tam_elem);
}

void adiciona_elemento(Vetor *V, void *x) {
  if (V->n == V->capacidade) {
    V->capacidade *= 2;
    // queremos um espaço que caiba 2x o numero de elementos que ja queremos
    V->dados = realloc(V->dados, V->tam_elem * V->capacidade);
  }
  V->n++;
  V->dados[V->n - 1] = *x;
}

int main() {

  ;

  return 0;
}

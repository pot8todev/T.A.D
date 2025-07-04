#pragma once

typedef struct Vetor Vetor;

Vetor *novo_vetor(int tam_elem);

int tamanho_vetor(Vetor *V);

void adiciona_elemento(Vetor *V, void *x);

void *elemento(Vetor *V, int i);

void remove_elemento(Vetor *V, int i);

void finaliza_vetor(Vetor *V);

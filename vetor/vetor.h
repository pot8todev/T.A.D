#pragma once

typedef struct Vetor Vetor;

Vetor *novo_vetor();

void finaliza_vetor(Vetor *V);

int tamanho_vetor(Vetor *V);

void adiciona_elemento(Vetor *V, float x);

float *elemento(Vetor *V, int i);

void remove_elemento(Vetor *V, int i);


#pragma once
#include <stdbool.h>
typedef struct Conjunto Conjunto;
Conjunto *novo_conjunto();
void finaliza_conjunto(Conjunto *S);
void adiciona_ao_conjunto(Conjunto *S, float x);
bool conjunto_contem(Conjunto *S, float x);
void remove_do_conjunto(Conjunto *S, float x);
void imprime_conjunto(Conjunto *S);
Conjunto *uniao(Conjunto *A, Conjunto *B);
Conjunto *intersecao(Conjunto *A, Conjunto *B);
Conjunto *diferenca(Conjunto *A, Conjunto *B);

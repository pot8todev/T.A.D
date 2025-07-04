#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *make_node(int data, Node *next);

void print_list(Node *head);

int tamanho_lista(Node *head);
Node *no_em(Node *head, int index);

Node *vetor_para_lista(int *v, int size);
Node *vetor_para_lista_Loop(int *v, int size);
// passamos por parametro a lista e o endereço anterior a ela;
Node *lista_invertida_recur(Node *head, Node *previous);

void free_list(Node *head);
Node *divide_lista(Node *head);
Node *insere_em_ordem(Node *head, int num);
Node *insere_em_ordem_Recur(Node *head, int num);
Node *merge(Node *a, Node *b);

Node *ordena_lista(Node *head);



#include "encadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Node *make_node(int data, Node *next) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = next;
  return node;
}

void print_list(Node *head) {
  Node *p;
  printf("\n");
  for (p = head; p != NULL; p = p->next) {
    printf("%d ", p->data);
  }
  printf("\n");
}
int tamanho_lista(Node *head) {
  int count = 0;
  for (Node *p = head; p != NULL; p = p->next) {
    count++;
  }
  return count;
}
void free_list(Node *head) {
  if (head != NULL) {
    free_list(head->next);
    free(head);
  }
}

Node *no_em(Node *head, int index) {
  int size = tamanho_lista(head);
  if (index >= size || index < 0) {
    printf("\ninsira index valido");
    return NULL;
  }
  Node *p = head;
  for (int i = 0; i < index; i++) {
    p = p->next;
  }

  return p;
}
Node *vetor_para_lista(int *v, int size) {
  Node *head;
  if (size != 0) {
    head = make_node(*v, vetor_para_lista(v + 1, (size - 1)));
  } else {
    return NULL;
  }
  return head;
}
Node *divide_lista(Node *head) {
  int middle = tamanho_lista(head) / 2;
  printf("\ntamanho : %d\tmiddle: %d\n", tamanho_lista(head), middle);
  if (middle == 0 || head == NULL) {
    return NULL;
  }

  Node *aux = head;
  Node *tail;
  for (int i = 1; i < middle; i++) {
    aux = aux->next;
  }
  tail = aux->next;
  aux->next = NULL;

  return tail;
}
Node *insere_em_ordem(Node *head, int num) {
  Node *tail = head;
  Node *value;
  // caso head seja vazio ou for menor que o primeiro elemento
  if (!tail || num < tail->data) {
    value = make_node(num, tail);
    return value;
  }

  while ((tail->next != NULL && num > tail->next->data)) {
    tail = tail->next;
  }

  value = make_node(num, tail->next);
  tail->next = value;

  return head;
}

Node *ordena_lista(Node *head) {
  Node *tail = head;
  Node *novo = NULL;
  while (tail) {
    novo = insere_em_ordem(novo, tail->data);
    tail = tail->next;
  }

  return novo;
}
Node *vetor_para_lista_Loop(int *v, int size) {
  Node *head = make_node(v[0], NULL);
  Node *tail = head;

  for (int i = 1; i < size; i++) {
    tail->next = make_node(v[i], NULL);
    tail = tail->next;
  }

  return head;
}
Node *insere_em_ordem_Recur(Node *head, int num) {
  Node *tail = head;
  if (tail != NULL && num > tail->data) {
    tail->next = insere_em_ordem_Recur(tail->next, num);
    return head;
  } else {
    tail = make_node(num, tail);
    return tail;
  }
}

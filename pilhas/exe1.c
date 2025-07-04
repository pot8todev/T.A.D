#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1024

typedef struct Pilha {

  char data[50];
  int capacity;

} Pilha;

Pilha *initPilha() {
  Pilha *P = malloc(sizeof(Pilha));
  P->capacity = 0;
  return P;
}
char top(Pilha *P1) { return P1->data[P1->capacity - 1]; }

void push(Pilha *p, char data) {
  assert(p->capacity < MAXSIZE);
  p->capacity++;
  p->data[p->capacity] = data;
}
void pop(Pilha *p) { p->capacity--; }

void print_pilha(Pilha *p) {
  int i = p->capacity;
  printf("\n");
  while (i >= 0) {
    printf("%c ", p->data[i]);
    i--;
  }
}
void pop_base(Pilha *p) {
  int i = 1;
  assert(p->capacity > 0);
  do {

    p->data[i] = p->data[i + 1];
    i++;
  } while (p->data[i + 1] != '\0');
  p->capacity--;
}

int main() {
  Pilha *P1 = initPilha();
  Pilha *P2 = initPilha();
  push(P1, 'A');
  push(P1, 'B');
  push(P1, 'C');
  push(P1, 'D');

  print_pilha(P1);

  push(P1, P1->data[1]);
  pop_base(P1);

  print_pilha(P1);

  return 0;
}

#include "fila.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 4

typedef struct Queue {
  char *data;
  int begin; // index
  int end;   // index
  int quantidade;

} Queue;

Queue *init_queue() {
  Queue *Q = malloc(sizeof(Queue));
  Q->quantidade = 0;
  Q->data = malloc(MAX_SIZE * sizeof(char));
  Q->begin = Q->end = 0;
  return Q;
}
void free_queue(Queue *Q) {
  free(Q->data);
  free(Q);
}
bool is_empty_queue(Queue *Q) { return Q->quantidade == 0; }

void move_end(Queue *Q) { Q->end = (Q->end + 1) % MAX_SIZE; }
void move_begin(Queue *Q) { Q->begin = (Q->begin + 1) % MAX_SIZE; }
char front(Queue *Q) { return Q->data[Q->begin]; }

void enqueue(Queue *Q, char x) {
  if (Q->quantidade >= MAX_SIZE) {
    printf("\nta cheio irmao\n");
    return;
  }
  Q->data[Q->end] = x;
  move_end(Q);
  Q->quantidade++;
  printf("\n\t %c adicionado! numero de elemento-: %d\n", x, Q->quantidade);
}

void dequeue(Queue *Q) {
  if (is_empty_queue(Q))
    return;
  Q->quantidade--;
  printf("\n%c REMOVIDO! numero de elemento-: %d\n", front(Q), Q->quantidade);
  move_begin(Q);
}
int main() {
  Queue *Q = init_queue();
  enqueue(Q, 'A');
  enqueue(Q, 'B');
  enqueue(Q, 'C');
  printf("%c ", front(Q));
  dequeue(Q);
  enqueue(Q, 'D');
  printf("%c ", front(Q));
  dequeue(Q);
  enqueue(Q, 'E');
  enqueue(Q, 'F');

  while (!is_empty_queue(Q)) {
    printf("%c ", front(Q));
    dequeue(Q);
  }
  free_queue(Q);
}

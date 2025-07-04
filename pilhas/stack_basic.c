
#include "stack.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Stack *init_stack() {
  Stack *S = malloc(sizeof(Stack));
  S->n = 0;
  return S;
}

void free_stack(Stack *S) { free(S); }

bool is_empty(Stack *S) { return S->n == 0; }

char top(Stack *S) {
  assert(!is_empty(S));
  return S->data[S->n - 1];
}

void push(Stack *S, char x) {
  assert(S->n < MAXSIZE);
  S->data[S->n++] = x;
}

void pop(Stack *S) {
  assert(S->n > 0);
  S->n--;
}
void print_stack(Stack *S) {
  assert(S->n > 0);
  printf("\n");
  while (!is_empty(S)) {
    printf("%c ", S->data[S->n - 1]); // Print the top element
    pop(S);
  }

  S->n--;
}

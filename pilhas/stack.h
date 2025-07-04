
#pragma once
#include <stdbool.h>

#define MAXSIZE 1024

typedef struct Stack {
  char data[MAXSIZE];
  int n;
} Stack;

Stack *init_stack();

void free_stack(Stack *S);

bool is_empty(Stack *S);

char top(Stack *S);

void push(Stack *S, char x);

void pop(Stack *S);

void print_stack(Stack *S);

bool opening(char c);

bool matching_pair(char c1, char c2);

void balanceado(char word[]);

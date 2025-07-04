#pragma once
#include <stdbool.h>

typedef struct Queue Queue;

Queue *init_queue();

void free_queue(Queue *Q);

bool is_empty_queue(Queue *Q);

char front(Queue *Q);

void enqueue(Queue *Q, char x);

void dequeue(Queue *Q);

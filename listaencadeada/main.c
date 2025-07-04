#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void print_list(Node *head) {
  for (Node *p = head; p != NULL; p = p->next) {
    printf("%d ", p->data);
  }
  printf("\n");
}

Node *newNode(int data, Node *next) {

  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = next;
  return newNode;
}
Node *vetor_para_lista(int v[], int size) {
  Node *head = newNode(v[0], NULL);
  Node *tail = head;

  for (int i = 1; i < size; i++) {
    tail->next = newNode(v[i], NULL);
    tail = tail->next;
  }
  return head;
}
void free_list(Node *head) {
  if (head) {

    free_list(head->next);
    free(head);
  }
}

int main() {
  int v[5] = {42, 15, 65, 98, 48};
  Node *head = vetor_para_lista(v, 5);
  print_list(head);
  free_list(head);
}

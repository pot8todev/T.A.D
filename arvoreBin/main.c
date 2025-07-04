#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct treeNode {
  int data;
  struct treeNode *right;
  struct treeNode *left;
} treeNode;

treeNode *criaNode(int data) {
  treeNode *T = malloc(sizeof(treeNode));
  T->data = data;
  T->left = NULL;
  T->right = NULL;
  return T;
}

void freeTree(treeNode *T) {
  if (T) {
    freeTree(T->left);
    freeTree(T->right);
    free(T);
  }
}
treeNode *find(treeNode *root, int data) {

  if (!root)
    return NULL;
  if (data < root->data) {
    root = find(root->left, data);
    return root;
  }
  if (data > root->data) {
    root = find(root->right, data);
    return root;
  } else {
    return root;
  }
}
treeNode *insere(treeNode *T, int data) {
  if (!T)
    return criaNode(data);

  if (data > T->data) {
    T->right = insere(T->right, data);
  } else if (data < T->data) {
    T->left = insere(T->left, data);
  }

  return T;
}

void printaCrescente(treeNode *root) { // em ordem
  if (!root)
    return;

  printaCrescente(root->left);
  printf("%d ", root->data);

  printaCrescente(root->right);
}
void printaPosOrdem(treeNode *root) { // em ordem
  if (!root)
    return;

  printaPosOrdem(root->left);

  printaPosOrdem(root->right);
  printf("%d ", root->data);
}
void printaPreOrdem(treeNode *root) { // em ordem
  if (!root)
    return;
  printf("%d ", root->data);

  printaPosOrdem(root->left);

  printaPosOrdem(root->right);
}
void printaDecrescente(treeNode *root) {
  if (!root)
    return;
  printaDecrescente(root->right);
  printf("%d ", root->data);

  printaDecrescente(root->left);
}

treeNode *minimo(treeNode *root) {
  if (root) {

    if (!root->left)
      return root;
    else {
      root = minimo(root->left);
      return root;
    }
  }
  return NULL;
}

treeNode *maximo(treeNode *root) {
  assert(root);

  while (root->right) {
    root = root->right;
  }
  return root;
}

treeNode *Delete(treeNode *root, int data) {
  if (root == NULL)
    return NULL;
  treeNode *aux;

  if (data < root->data) {
    root->left = Delete(root->left, data);
  } else if (data > root->data) {
    root->right = Delete(root->right, data);
  } else {
    // se o nodulo que iremos mover, nao tiver filhos
    if (!root->right && !root->left) {
      free(root);
      return NULL;
    } else if (!root->right) {
      treeNode *deleted = root->left;
      free(root);
      return deleted;
    } else if (!root->left) {
      treeNode *deleted = root->right;
      free(root);
      return deleted;
    } else {
      bool esquerda = root->left != NULL;
      bool direita = root->right != NULL;
      aux = esquerda ? maximo(root->left) : minimo(root->right);
      root->data = aux->data;
      if (esquerda)
        root->left = Delete(root->left, aux->data);
      else
        root->right = Delete(root->right, aux->data);
    }
  }
  return root;
}
/*
aqui ja temos o no
#com o valor adequado para troca
#o no que aponta para ele
# o valor
 */

int main() {
  treeNode *root = NULL;
  root = insere(root, 2);
  root = insere(root, 4);
  root = insere(root, 12);
  root = insere(root, 22);
  root = insere(root, 32);
  root = insere(root, 8);
  root = insere(root, 0);
  root = insere(root, 7);
  root = insere(root, 1);
  root = insere(root, 7);
  printf("\n root: ");
  printaCrescente(root);

  Delete(root, 22);

  printf("\n pos Delete: ");
  printaCrescente(root);
  printf("\n");
  // printaDecrescente(root);
  //
  // printf("\n");
  // printaPosOrdem(root);
  // printf("\n");

  // printaPreOrdem(root);
  //
  // treeNode *found = find(root, 7);
  //
  // found ? printf("\n achei:%d", found->data) : printf("\nnao ta la chefe");
  printf("\n raiz: %d", root->data);

  return 0;
}

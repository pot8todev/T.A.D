#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct treeNode {
  int data;
  struct treeNode *left;
  struct treeNode *right;
} treeNode;

treeNode *init_node(int data) {
  treeNode *root = malloc(sizeof(treeNode));
  root->data = data;
  root->right = NULL;
  root->left = NULL;
  return root;
}
void free_tree(treeNode *root) {
  if (!root)
    return;
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}
void insert(treeNode *root, int data) {
  if (!root)
    return;
  while (root) {
    if (data > root->data) {
      if (root->right) {
        root = root->right;
      } else {
        root->right = init_node(data);
        break;
      }
    } else if (data < root->data) {
      if (root->left) {
        root = root->left;
      } else {
        root->left = init_node(data);
      }
    } else {
      break; // valor já existe; opcional dependendo da política da sua árvore
    }
  }
}
void print_tree(treeNode *root) {
  print_tree(root->left);
  printf("%d ", root->data);
  print_tree(root->right);
}

int main() {

  treeNode *root = init_node(25);
  printf("%d", root->data);
  insert(root, 12);
  insert(root, 1);
  insert(root, 2);
  insert(root, 22);

  print_tree(root);

  free_tree(root);

  return 0;
}

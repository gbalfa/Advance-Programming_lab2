#include <stdlib.h>

#include "ArbolAVL.h"

/* Given a binary tree, print its AVLNodes in inorder */
void _statisticsInorder(struct AVLNode *AVLNode, int *position) {
  if (AVLNode == NULL) return;
  /* first recur on left child */
  _statisticsInorder(AVLNode->left, position);
  /* TODO: Evento según posición */
  /* now recur on right child */
  _statisticsInorder(AVLNode->right, position);
}

void statisticsInorder(struct AVLNode *root) {
  int position = 0;
  _statisticsInorder(root, &position);
}

double minAVL(struct AVLNode *arbol) {
  if (arbol->left == NULL) {
    return arbol->key;
  }
  return minAVL(arbol->left);
}

double maxAVL(struct AVLNode *arbol) {
  if (arbol->right == NULL) {
    return arbol->key;
  }
  return maxAVL(arbol->right);
}

void cuartilesAVL(struct AVLNode *arbol) {}

void medianaAVL(struct AVLNode *arbol) {}

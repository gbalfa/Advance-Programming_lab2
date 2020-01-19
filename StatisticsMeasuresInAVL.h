#include <stdlib.h>

#include "ArbolAVL.h"

struct StatsNode {
  int desired_pos;
  double key;
  int quartile;
  struct StatsNode *next;
};

void pushStatsNode(struct StatsNode **root, int desired_pos, int q) {
  struct StatsNode *new_node;
  new_node = (struct StatsNode *)malloc(sizeof(struct StatsNode));
  new_node->desired_pos = desired_pos;
  new_node->key = -1;
  new_node->quartile = q;
  new_node->next = (*root);
  (*root) = new_node;
}

/* Given a binary tree, print its AVLNodes in inorder */
void _statisticsInorder(struct AVLNode *AVLNode, struct StatsNode **desired_pos,
                        int *position) {
  if (AVLNode == NULL) return;
  /* first recur on left child */
  _statisticsInorder(AVLNode->left, desired_pos, position);
  /* TODO: Evento según posición (deciles, cuartiles, mediana) */
  (*position) += AVLNode->count;
  /* printf("%d\n", (*position)); */

  if ((*desired_pos) == NULL) return;
  if ((*position) >= (*desired_pos)->desired_pos) {
    (*desired_pos)->key = AVLNode->key;
    (*desired_pos) = (*desired_pos)->next;
    if ((*desired_pos) == NULL) return;
    while ((*position) >= (*desired_pos)->desired_pos) {
      (*desired_pos)->key = AVLNode->key;
      (*desired_pos) = (*desired_pos)->next;
      if ((*desired_pos) == NULL) return;
    }
  }
  /* if ((*position == ) */
  /* now recur on right child */
  _statisticsInorder(AVLNode->right, desired_pos, position);
}

void statisticsInorder(struct AVLNode *root, int n) {
  int position;
  struct StatsNode *desired_pos = NULL, *tmp;
  int i;
  for (i = 9; i > 0; --i) {
    if (i == 2)
      pushStatsNode(&desired_pos, ((n + 1) / 4), 1);
    else if (i == 5)
      pushStatsNode(&desired_pos, ((n + 1) / 2), 1);
    else if (i == 7)
      pushStatsNode(&desired_pos, ((n + 1) * 3 / 4), 1);
    pushStatsNode(&desired_pos, ((n + 1) * i / 10), 0);
  }
  position = 0;
  tmp = desired_pos;
  _statisticsInorder(root, &tmp, &position);

  tmp = desired_pos;
  printf("\nPercentiles:\n");
  while (tmp != NULL) {
    if (tmp->quartile == 0) {
      printf("%le\t", tmp->key);
    }
    tmp = tmp->next;
  }
  tmp = desired_pos;
  printf("\nQuartiles:\n");
  while (tmp != NULL) {
    if (tmp->quartile == 1) {
      printf("%le\t", tmp->key);
    }
    tmp = tmp->next;
  }
}

struct AVLNode *minAVL(struct AVLNode *arbol) {
  if (arbol->left == NULL) {
    return arbol;
  }
  return minAVL(arbol->left);
}

struct AVLNode *maxAVL(struct AVLNode *arbol) {
  if (arbol->right == NULL) {
    return arbol;
  }
  return maxAVL(arbol->right);
}

void _modaAVL(struct AVLNode *AVLNode, double *moda, int *count_moda) {
  if (AVLNode == NULL) return;
  /* first recur on left child */
  _modaAVL(AVLNode->left, moda, count_moda);
  /* TODO: Evento según posición */
  if (AVLNode->count > (*count_moda)) {
    (*count_moda) = AVLNode->count;
    (*moda) = AVLNode->key;
  }
  /* now recur on right child */
  _modaAVL(AVLNode->right, moda, count_moda);
}

void modaAVL(struct AVLNode *AVLNode) {
  double moda;
  int count_moda = 0;
  _modaAVL(AVLNode, &moda, &count_moda);
  printf("\nmoda: %le\t#: %d", moda, count_moda);
}

void _diffNumbersAVL(struct AVLNode *AVLNode, int *cantidad) {
  if (AVLNode == NULL) return;
  /* first recur on left child */
  _diffNumbersAVL(AVLNode->left, cantidad);
  ++(*cantidad);
  /* now recur on right child */
  _diffNumbersAVL(AVLNode->right, cantidad);
}

void diffNumbersAVL(struct AVLNode *root) {
  int cantidad = 0;
  _diffNumbersAVL(root, &cantidad);
  printf("\n# of different numbers: %d", cantidad);
}

#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

// An AVL tree AVLNode
struct AVLNode {
  double key;
  struct AVLNode *left;
  struct AVLNode *right;
  int height;
  int count;
};

// A utility function to get the height of the tree
int height(struct AVLNode *AVLNode) {
  if (AVLNode == NULL) return 0;
  return AVLNode->height;
}

// A utility function to get maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

/* newAVLNode */
struct AVLNode *newAVLNode(double key) {
  struct AVLNode *AVLNode = (struct AVLNode *)malloc(sizeof(struct AVLNode));
  AVLNode->key = key;
  AVLNode->left = NULL;
  AVLNode->right = NULL;
  AVLNode->height = 1;  // new AVLNode is initially added at leaf
  AVLNode->count = 1;
  return (AVLNode);
}

// A utility function to right rotate subtree rooted with y
struct AVLNode *rightRotate(struct AVLNode *y) {
  struct AVLNode *x = y->left;
  struct AVLNode *T2 = x->right;

  // Perform rotation
  x->right = y;
  y->left = T2;

  // Update heights
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  // Return new root
  return x;
}

// A utility function to left rotate subtree rooted with x
struct AVLNode *leftRotate(struct AVLNode *x) {
  struct AVLNode *y = x->right;
  struct AVLNode *T2 = y->left;

  // Perform rotation
  y->left = x;
  x->right = T2;

  // Update heights
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  // Return new root
  return y;
}

// Get Balance factor of AVLNode N
int getBalance(struct AVLNode *N) {
  if (N == NULL) return 0;
  return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with AVLNode and returns the new root of the subtree.
struct AVLNode *insert(struct AVLNode *AVLNode, double key) {
  /* 1. Perform the normal BST insertion */
  if (AVLNode == NULL) return (newAVLNode(key));

  if (key < AVLNode->key)
    AVLNode->left = insert(AVLNode->left, key);
  else if (key > AVLNode->key)
    AVLNode->right = insert(AVLNode->right, key);
  else {  // Equal keys
    ++AVLNode->count;
    return AVLNode;
  }

  /* 2. Update height of this ancestor AVLNode */
  AVLNode->height = 1 + max(height(AVLNode->left), height(AVLNode->right));

  /* 3. Get the balance factor of this ancestor
          AVLNode to check whether this AVLNode became
          unbalanced */
  int balance = getBalance(AVLNode);

  // If this AVLNode becomes unbalanced, then
  // there are 4 cases

  // Left Left Case
  if (balance > 1 && key < AVLNode->left->key) return rightRotate(AVLNode);

  // Right Right Case
  if (balance < -1 && key > AVLNode->right->key) return leftRotate(AVLNode);

  // Left Right Case
  if (balance > 1 && key > AVLNode->left->key) {
    AVLNode->left = leftRotate(AVLNode->left);
    return rightRotate(AVLNode);
  }

  // Right Left Case
  if (balance < -1 && key < AVLNode->right->key) {
    AVLNode->right = rightRotate(AVLNode->right);
    return leftRotate(AVLNode);
  }

  /* return the (unchanged) AVLNode pointer */
  return AVLNode;
}

/* Given a binary tree, print its AVLNodes in inorder */
void printInorder(struct AVLNode *AVLNode) {
  if (AVLNode == NULL) return;
  /* first recur on left child */
  printInorder(AVLNode->left);
  /* then print the data of AVLNode */
  int count = AVLNode->count;
  for(;count > 0; --count){
    printf("%lf\t", AVLNode->key);
  }
  /* now recur on right child */
  printInorder(AVLNode->right);
}

/**
 *  \brief Creates an AVL tree from given file.
 */
struct AVLNode *GenerateAVL(struct List *lista) {
  // Initialices the tree root.
  struct AVLNode *root = NULL;

  struct Node *tmp = lista->head;
  while (tmp != NULL) {
    root = insert(root, tmp->key);
    tmp = tmp->next;
  }
  return root;
}

/* free AVL */
void freeAVL(struct AVLNode *AVLNode) {
  if (AVLNode == NULL) return;
  /* first recur on left child */
  freeAVL(AVLNode->left);
  /* now recur on right child */
  freeAVL(AVLNode->right);
  /* then free the AVLNode */
  free(AVLNode);
}

#endif /* ARBOLAVL_H */

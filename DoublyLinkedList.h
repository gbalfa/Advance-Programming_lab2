#ifndef DOUBLYLINKEDLISTNODE_H
#define DOUBLYLINKEDLISTNODE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Doubly linked list polynomial with head and tail */
struct List {
  struct Node *head;
  struct Node *tail;
};

/* A node of the doubly linked list polynomial */
struct Node {
  double key; /* coefficient */
  struct Node *next;
  struct Node *prev;
};

/**
 *  Push a node into a polynomial.
 *
 *  Function to insert a polynomial node at the beginning of the Doubly Linked
 *  List.
 *
 *  @poly Polinomial struct.
 *  @new_coeff Monomial coefficient.
 *  @new_exp Monomial exponent.
 */
void push(struct List *list, double key) {
  /* allocate node */
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  /* put in the data  */
  new_node->key = key;

  /* since we are adding at the beginning,
     prev is always NULL */
  new_node->prev = NULL;

  /* link the old node off the new node */
  new_node->next = (list->head);

  /* change prev of head node to new node */
  if (list->head != NULL)
    (list->head)->prev = new_node;

  /* move the head to point to the new node */
  list->head = new_node;

  /* link the tail  */
  if (list->tail == NULL) {
    list->tail = list->head;
  }
}

/**
 *  Append a node into a polynomial.
 *
 *  Function to insert a polynomial node at the end of the Doubly Linked
 *  List.
 *
 *  @poly Polinomial struct.
 *  @new_coeff Monomial coefficient.
 *  @new_exp Monomial exponent.
 */
void append(struct List *list, double key) {
  /* allocate node */
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  /* put in the data  */
  new_node->key = key;

  /* since we are adding at the end,
     next is always NULL */
  new_node->next = NULL;

  /* link the old node off the new node */
  new_node->prev = (list->tail);

  /* change next of tail node to new node */
  if (list->tail != NULL)
    (list->tail)->next = new_node;

  /* move the tail to point to the new node */
  list->tail = new_node;

  /* link the head  */
  if (list->head == NULL) {
    list->head = list->tail;
  }
}

/**
 *  \brief Generates the polynomial.
 *
 *  Generates a random polynomial pushing (n+1) nodes into a doublylinkedlist.
 *
 *  \param n: Polynomial degree.
 */
struct List *GenerateList(FILE * file) {
  /* Intializes list */
  struct List *new_list =
      (struct List *)malloc(sizeof(struct List));
  new_list->head = NULL;
  new_list->tail = NULL;
  int i;
  double x;
  i = 0;
  while (1 == fscanf(file, "%le", &x)){
      push(new_list, x);
    i++;
  }
  printf("%d\n", i);
  return new_list;
}

/**
 *  \brief Frees the list memory.
 *
 *  \param List struct.
 */
void freeList(struct List *list) {
  struct Node *tmp;
  while (list->head != NULL) {
    tmp = list->head;
    list->head = list->head->next;
    free(tmp);
  }
  free(list);
}

/**
 *  \brief Prints a list.
 *
 *  Function to print a list representated by a doubly linked list.
 *
 *  \param List's head.
 */
void printList(struct List *poly) {
  struct Node *node = poly->head;

  /* first node */
  printf("%ef", node->key);
  node = node->next;

  /* the rest of the nodes */
  while (node != NULL) {
  printf("%ef", node->key);
    node = node->next;
  }
  printf("\n");
  return;
}

#endif /* DOUBLYLINKEDLISTNODE_H */

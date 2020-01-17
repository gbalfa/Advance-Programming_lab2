#include "DoublyLinkedList.h"
/**
 *  \brief Swap
 */
void Swap(struct Node *a, struct Node *b) {
  double tmp = a->key;
  a->key = b->key;
  b->key = tmp;
}

/**
 *  \brief Hoare partition algorithm.
 */
struct Node *HoarePartition(struct Node *start, struct Node *end) {
  double p = start->key;
  struct Node *i = start, *j = end->next;
  while (i != j && i->prev != j) {
    while (j != start) {
      j = j->prev;
      if (j->key <= p) break;
    }
    while (i != end) {
      i = i->next;
      if (i->key >= p) break;
    }
    Swap(i, j);
  }
  Swap(i, j);
  Swap(start, j);
  return j;
}

/**
 *  \brief QuickSort auxiliar function.
 */
void _QuickSort(struct Node *start, struct Node *end) {
  if (end != NULL && start != end && start != end->next) {
    struct Node *s = HoarePartition(start, end);
    _QuickSort(start, s->prev);
    _QuickSort(s->next, end);
  }
}

/**
 *  \brief Quicksort.
 *
 *  Quicksort using a doubly linked list and Hoarepartition.
 */
void QuickSort(struct List *lista) {
  struct Node *sentinel = (struct Node *)malloc(sizeof(struct Node));
  sentinel->key = 0;
  sentinel->next = NULL;
  sentinel->prev = lista->tail;
  lista->tail->next = sentinel;

  _QuickSort(lista->head, lista->tail);

  lista->tail->next = NULL;
  free(sentinel);
}

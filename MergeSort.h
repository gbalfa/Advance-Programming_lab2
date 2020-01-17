#include <math.h>
#include "DoublyLinkedList.h"

/**
 *  \brief Merge auxiliar function 2.
 */
struct Node *Merge(struct Node *B, struct Node *C, struct Node *B_tail, struct Node *C_tail, struct Node **tail) {
  if(B == NULL) return C;
  if(C == NULL) return B;
  struct Node *i = B, *j = C, *A = NULL, *tmp, *new_tail;
  if (i->key <= j->key) {
    tmp = i->next;
    i->next = NULL;
    A = i;
    new_tail = A;
    i = tmp;
  } else {
    tmp = j->next;
    j->next = NULL;
    A = j;
    new_tail = A;
    j = tmp;
  }
  while (i != NULL && j != NULL) {
    if (i->key <= j->key) {
      tmp = i->next;
      i->next = NULL;
      new_tail->next = i;
      new_tail = i;
      i = tmp;
    } else {
      tmp = j->next;
      j->next = NULL;  //
      new_tail->next = j;
      new_tail = j;
      j = tmp;
    }
  }
  if (i == NULL){
    new_tail->next = j;
    new_tail = C_tail;
  }
  else{
    new_tail->next = i;
    new_tail = B_tail;
  }
  (*tail) = new_tail;
  return A;
}

/**
 *  \brief Merge Sort auxiliar 1.
 */
struct Node *_MergeSort(struct Node *head, struct Node **tail, int n) {
  if (n > 1) {
    double half = n / 2.0;
    int h_floor = (int)floor(half), h_ceil = (int)ceil(half);
    struct Node *tmp = head, *tmp2, *A, *B, *C;
    int i = 0;
    while(i < h_floor - 1){
      tmp = tmp->next;
      ++i;
    }
    tmp2 = tmp->next;
    tmp->next = NULL;
    B = _MergeSort(head, &tmp,  h_floor);
    C = _MergeSort(tmp2, tail, h_ceil);
    A = Merge(B, C, tmp, (*tail), tail);
    return A;
  }
  return head;
}

struct List *MergeSort(struct List *lista){
  lista->head = _MergeSort(lista->head, &lista->tail, lista->n);
  return lista;
}

#include <stdlib.h>

#include "DoublyLinkedList.h"

void medianaList(struct List *lista) {
  struct Node *aux = lista->head;
  for (int i = 1; i != lista->n / 2; i++) {
    aux = aux->next;
  }
  printf("%le\n", aux->key);
  return;
}

void cuartilesList(struct List *lista) {
  printf("\nQuartiles:\t");
  struct Node *aux = lista->head;
  for (int i = 1; i != lista->n * 3 / 4; i++) {
    if (i == lista->n / 4) {
      printf("%le\t", aux->key);
    }
    if (i == lista->n / 2) {
      printf("%le\t", aux->key);
    }
    aux = aux->next;
  }
  printf("%le\n", aux->key);
  return;
}

void decilesList(struct List *lista) {
  printf("\nDeciles:\n");
  struct Node *aux = lista->head;
  int decil = 1;
  for (int i = 1; i <= lista->n * 9 / 10; i++) {
    if (i == lista->n * decil / 10) {
      printf("%le\t", aux->key);
      ++decil;
    }
    aux = aux->next;
  }
  printf("\n");
  return;
}

void moda(struct List *lista) {
  double maximo;
  int maximoVeces = 0;
  double iterador = lista->head->key;
  int iteradorVeces = 0;
  struct Node *aux = lista->head;
  while (aux != NULL) {
    if (aux->key != iterador) {
      if (iteradorVeces > maximoVeces) {
        maximo = iterador;
        maximoVeces = iteradorVeces;
      }
      iteradorVeces = 1;
      iterador = aux->key;
    } else {
      iteradorVeces++;
    }
    aux = aux->next;
  }
  printf("\nmoda: %le\t#: %d", maximo, maximoVeces);
}

int cantidadDistintos(struct List *lista) {
  int result = 1;
  struct Node *aux = lista->head, *tmp;
  while (aux != NULL && aux->next != NULL) {
    tmp = aux->next;
    while(tmp != NULL && tmp->key == aux->key){
      tmp = tmp->next;
    }
    ++result;
    aux = tmp;
  }
  return result;
}

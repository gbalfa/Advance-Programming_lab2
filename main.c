#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "ArbolAVL.h"
#include "DoublyLinkedList.h"
#include "MergeSort.h"
#include "QuickSort.h"

int main() {
  FILE *archivo;
  archivo = fopen("ArchivoA.tex", "r");
  /* MergeSort(numbersArray, i); */
  /* QuickSort(numbersArray, 0, i - 1); */
  /* PrintArray(numbersArray, i); */
  /* ArrayToAVL(numbersArray, i); */
  struct List *lista = GenerateList(archivo);
  /* printList(lista); */
  freeList(lista);

  int fclose(FILE * archivo);
  return 0;
}

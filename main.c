#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
  double time_spent;
  clock_t begin, end;

  time_spent = 0.0;
  begin = clock();
  /* struct AVLNode *avl = GenerateAVL(archivo); */
  struct List *lista = GenerateList(archivo);
  QuickSort(lista);

  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%lf\n", time_spent);
  /* printList(lista); */
  /* printInorder(avl); */
  freeList(lista);

  int fclose(FILE * archivo);
  return 0;
}

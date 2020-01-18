#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ArbolAVL.h"
#include "DoublyLinkedList.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "StatisticsMeasuresInAVL.h"
#include "StatisticsMeasuresInLists.h"

int main() {
  struct AVLNode *arbol;
  struct List *lista;
  char input, input2, showStatistics;
  /* int n; */
  FILE *archivo;
  double time_spent;
  clock_t begin, end;
  do {
    printf("\n#################### Menu ####################");
    printf("\n1. MergeSort");
    printf("\n2. QuickSort");
    printf("\n3. AVL");
    printf("\n0. exit");
    printf("\nChoose an option: ");
    scanf("\n%c", &input);
    if (input == '0') {
      return 0;  // Program will be terminated if 0 is pressed
    }

    printf("\n1. archivoPrueba");
    printf("\n2. ArchivoB");
    printf("\n3. ArchivoC");
    printf("\n0. exit");
    printf("\nChoose an option: ");
    scanf("\n%c", &input2);
    if (input2 == '1') {
      archivo = fopen("ArchivoA.tex", "r");
    } else if (input2 == '2') {
      archivo = fopen("ArchivoB.tex", "r");
    } else if (input2 == '2') {
      archivo = fopen("ArchivoC.tex", "r");
    }
    switch (input) {
      case '1':  // Mergesort.
        if (input == '1') {
          lista = GenerateList(archivo);
          time_spent = 0.0;
          begin = clock();
          lista = MergeSort(lista);
          end = clock();
          time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
          printf("Time elapsed is %f seconds", time_spent);
          printf(", show statistics? (y/n): ");
          scanf("\n%c", &showStatistics);
          if (showStatistics == 'y') {
            cuartilesList(lista);
            decilesList(lista);
            printf("\nmaximum: %f", lista->tail->key);
            printf("\nminimum: %f", lista->head->key);
            printf("\nmode: %lf", moda(lista));
            printf("\n# of different numbers: %d", cantidadDistintos(lista));
          }
          freeList(lista);
        }
        break;

      case '2':  // QuickSort
        if (input == '2') {
          lista = GenerateList(archivo);
          time_spent = 0.0;
          begin = clock();
          QuickSort(lista);
          end = clock();
          time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
          printf("Time elapsed is %f seconds", time_spent);
          printf(", show statistics? (y/n): ");
          scanf("\n%c", &showStatistics);
          if (showStatistics == 'y') {
            cuartilesList(lista);
            decilesList(lista);
            printf("\nmaximum: %f", lista->tail->key);
            printf("\nminimum: %f", lista->head->key);
            printf("\nmode: %f", moda(lista));
            printf("\n# of different numbers: %d", cantidadDistintos(lista));
          }
          freeList(lista);
        }
        break;
      case '3':  // AVL
        if (input == '3') {
          time_spent = 0.0;
          begin = clock();
          arbol = GenerateAVL(archivo);
          end = clock();
          time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
          printf("Time elapsed is %f seconds", time_spent);
          printf(", show statistics? (y/n): ");
          scanf("\n%c", &showStatistics);
          if (showStatistics == 'y') {
            printf("\nmaximum: %f", maxAVL(arbol));
            printf("\nminimum: %f", minAVL(arbol));
            printf("\n");
            printInorder(arbol);
          }
          freeAVL(arbol);
        }
        break;
      default:
        printf("\n############### Invalid option ###############\n");
        break;
    }
    printf("\n");
  } while (1);
  return 0;
}

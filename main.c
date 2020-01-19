/* Compilación: gcc main.c -lm */

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

    printf("\n1. ArchivoA");
    printf("\n2. ArchivoB");
    printf("\n3. ArchivoC");
    /* printf("\n4. archivoPrueba"); */
    printf("\n0. back");
    printf("\nChoose an option: ");
    scanf("\n%c", &input2);
    switch (input2) {
      case '1': {
        archivo = fopen("ArchivoA.tex", "r");
        break;
      }
      case '2': {
        archivo = fopen("ArchivoB.tex", "r");
        break;
      }
      case '3':
        archivo = fopen("ArchivoC.tex", "r");
        break;
      case '4':
        archivo = fopen("archivoPrueba.tex", "r");
        break;

      case '0': {
        continue;
        break;
      }
      default:
        printf("\n############### Invalid option ###############\n");
        break;
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
            printf("\nmaximum: %le", lista->tail->key);
            printf("\nminimum: %le", lista->head->key);
            moda(lista);
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
            printf("\nmaximum: %le", lista->tail->key);
            printf("\nminimum: %le", lista->head->key);
            moda(lista);
            printf("\n# of different numbers: %d", cantidadDistintos(lista));
          }
          freeList(lista);
        }
        break;
      case '3':  // AVL
        if (input == '3') {
          lista = GenerateList(archivo);
          time_spent = 0.0;
          begin = clock();
          arbol = GenerateAVL(lista);
          end = clock();
          time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
          printf("Time elapsed is %f seconds", time_spent);
          printf(", show statistics? (y/n): ");
          scanf("\n%c", &showStatistics);
          if (showStatistics == 'y') {
            struct AVLNode *notaMax = maxAVL(arbol);
            struct AVLNode *notaMin = minAVL(arbol);
            printf("\nmaximum: %lf\t#: %d", notaMax->key, notaMax->count);
            printf("\nminimum: %lf\t#: %d", notaMin->key, notaMin->count);
            statisticsInorder(arbol, lista->n);
            /* printf("\n"); */
            /* printInorder(arbol); */
            modaAVL(arbol);
            diffNumbersAVL(arbol);
          }
          freeAVL(arbol);
          freeList(lista);
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

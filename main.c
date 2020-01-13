#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "MergeSort.h"
#include "QuickSort.h"

#define MAX_SIZE 1000

void PrintArray(double A[], int n) {
  for (int j = 0; j < n; j++) {
    printf("%lf\t", A[j]);
  }
  printf("\n");
}

int main() {
  FILE *archivo;
  archivo = fopen("archivo1.tex", "r");

  int i;
  double numbersArray[MAX_SIZE];
  i = 0;
  while (i < MAX_SIZE && 1 == fscanf(archivo, "%lf", &numbersArray[i])) {
    i++;
  }
  /* MergeSort(numbersArray, i); */
  QuickSort(numbersArray, 0, i - 1);
  PrintArray(numbersArray, i);

  int fclose(FILE * archivo);
  return 0;
}

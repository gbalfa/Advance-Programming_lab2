#include <math.h>

/**
 *  \brief Copies an array.
 *
 *  Copies an array from start to end (inclusive delimiter).
 */
void CopyArray(double input[], double output[], int start, int end,
               int outStart) {
  int i = start, j = outStart;
  for (; i <= end; i++, j++) {
    output[j] = input[i];
  }
}

/**
 *  \brief Merge auxiliar function.
 */
void Merge(double B[], double C[], double A[], int nb, int nc) {
  int i = 0, j = 0, k = 0;
  while (i < nb && j < nc) {
    if (B[i] <= C[j]) {
      A[k] = B[i];
      i++;
    } else {
      A[k] = C[j];
      j++;
    }
    k++;
  }
  if (i == nb)
    CopyArray(C, A, j, nc - 1, k);
  else
    CopyArray(B, A, i, nb - 1, k);
}

/**
 *  \brief Merge Sort.
 */
void MergeSort(double A[], int n) {
  if (n > 1) {
    double half = n / 2.0;
    int h_floor = (int)floor(half), h_ceil = (int)ceil(half);
    double B[h_floor], C[h_ceil];
    CopyArray(A, B, 0, h_floor - 1, 0);
    CopyArray(A, C, h_floor, n - 1, 0);
    MergeSort(B, h_floor);
    MergeSort(C, h_ceil);
    Merge(B, C, A, h_floor, h_ceil);
  }
}

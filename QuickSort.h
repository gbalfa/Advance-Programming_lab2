/**
 *  \brief Swap
 */
void Swap(double A[], int i, int j) {
  double tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
}

/**
 *  \brief Hoare partition algorithm.
 */
int HoarePartition(double A[], int start, int end) {
  double p = A[start];
  int i = start, j = end + 1;
  while (i < j) {
    while (j > start) {
      --j;
      if (A[j] <= p) break;
    }
    while (i < end) {
      ++i;
      if (A[i] >= p) break;
    }
    Swap(A, i, j);
  }
  Swap(A, i, j);
  Swap(A, start, j);
  return j;
}

/**
 *  \brief QuickSort
 */
void QuickSort(double A[], int start, int end) {
  if (start < end) {
    double s = HoarePartition(A, start, end);
    QuickSort(A, start, s - 1);
    QuickSort(A, s + 1, end);
  }
}

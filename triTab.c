#include "triTab.h"

int estTabTrie(int tab[]) // return 1 if tab is already sorted, and 0 if not.
{
  int i;
  for (i = 0; i < TAILLE - 1; i++) {
    if (tab[i] > tab[i + 1]) {
      return 0;
    }
  }

  return 1;
}

//************** quickSort : 3 functions to sort the table passed in parameters
//*****************//

int partition(int A[], int deb, int fin) // return the pivot
{
  int temp;
  int inf = deb + 1;
  int sup = fin;

  while (inf <= sup) { // find the pivot

    while (A[sup] > A[deb]) {
      sup--;
    }
    while (A[inf] <= A[deb]) {
      inf++;
    }
    // swap inf and sup
    if (inf < sup) {
      temp = A[inf];
      A[inf] = A[sup];
      A[sup] = temp;
      inf++;
      sup--;
    }
  }
  // place the pivot
  temp = A[deb];
  A[deb] = A[sup];
  A[sup] = temp;
  return sup;
}

void quickSort(int A[], int deb, int fin, int taille) {
  int pivot;
  if (deb < fin) {
    pivot = partition(A, deb, fin);
    // the left side of the table
    quickSort(A, deb, pivot - 1, taille);
    // the right side of the table
    quickSort(A, pivot + 1, fin, taille);
  }
}

void quickSortFinal(int A[], int taille) {
  quickSort(A, 0, taille - 1, taille);
}

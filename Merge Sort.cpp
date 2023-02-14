#include <iostream>
using namespace std;

void merge(int arr[], int p, int q, int r)
{
  int nL = q - p + 1;
  int nR = r - q;
  int L[nL];
  int R[nR];

  int a, b;
  for(a = 0; a<nL; a++)
  {
      L[a] = arr[p + a];
  }

  for(b = 0; b < nR; b++)
  {
      R[b] = arr[q + 1 + b];
  }

  int i = 0, j = 0, k = p;

  while (i<nL && j<nR)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i = i+1;
    }
    else
    {
        arr[k] = R[j];
        j = j+1;
    }
    k = k+1;
  }

  while (i < nL)
  {
    arr[k] = L[i];
    i = i+1;
    k = k+1;
  }

  while (j < nR)
  {
    arr[k] = R[j];
    j = j+1;
    k = k+1;
  }
}

void mergeS(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    mergeS(arr, l, m);
    mergeS(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void display(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
      cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int size = sizeof(arr) / sizeof(arr[0]);
  mergeS(arr, 0, size - 1);
  cout<<"Sorted array: ";
  display(arr, size);
  return 0;
}

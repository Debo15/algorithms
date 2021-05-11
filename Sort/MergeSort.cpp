#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int uint;
template<class T>
void merge(T* arr, uint l, uint mid, uint r){

  size_t LSize = mid - l + 1, RSize = r - mid;
  
  vector<int> L(LSize), R(RSize);

  for (size_t i = 0; i < LSize; i++)
    L[i] = arr[l + i];

  for (size_t j = 0; j < RSize; j++)
    R[j] = arr[mid + 1 + j];

  size_t i = 0, j = 0, k = l;

  while (i < LSize && j < RSize){
    if (L[i] <= R[j])
      arr[k] = L[i], i++;
    else
      arr[k] = R[j], j++;
    k++;
  }

  while (i < LSize)
    arr[k++] = L[i++];
  while (j < RSize)
    arr[k++] = R[j++];
  
}

template<class T>
void __mergeSort(T* arr, uint l, uint r){
  if (l >= r)
    return; // base case, when it's impossible to divide the segment (size = 1) l <= r

  int mid = (l+r)/2;
  __mergeSort(arr, l, mid);
  __mergeSort(arr, mid+1, r);
  merge(arr, l, mid, r);
}

template<class T>
void mergeSort(T* arr, size_t size){ // the array, its size;
  return __mergeSort(arr, 0, size-1);
}

int main() {
  int arr[] = {6, 3, 2, 9, 9, 10, 2, 23, -13, -4};
  size_t size = sizeof(arr)/sizeof(arr[0]);
  mergeSort(arr, size);
  for (size_t i = 0; i < size; i++)cout << arr[i] << ' ';
  return 0;
}
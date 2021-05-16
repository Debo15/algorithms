#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
template<class T>
int partition(T* arr, int low, int high){ // size: get the max heap to this size (e.g [idx, size) )
  int pivot = arr[high-1];
  int swapper_idx = low;
  for (int i = low; i < high -1; i++){
    if (arr[i] < pivot){
      swap(arr[i], arr[swapper_idx]);
      swapper_idx++;
    }
  }
  swap(arr[high-1], arr[swapper_idx]);
  return swapper_idx;
}

template<class T>
void __quickSort(T* arr, int low, int high){

  if (low >= high) // Divide and Conquare Global-Base
    return;
  
  int pi = partition(arr, low, high);

  __quickSort(arr, low, pi);
  __quickSort(arr, pi + 1, high);
}

template<class T>
void quickSort(T*arr, size_t size){
  return __quickSort(arr, 0, size);
}

int main() {

  int arr[] = {6, 3, 2, 9, 9, 10, 2, 23, -13, -4};
  size_t size = sizeof(arr)/sizeof(arr[0]);

  quickSort(arr, size);

  for (size_t i = 0; i < size; i++)cout << arr[i] << ' ';

  return 0;
}
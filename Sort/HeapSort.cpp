#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
template<class T>
void heapify(T* arr, int size, int idx){ // size: get the max heap to this size (e.g [idx, size) )

  int l = idx*2 + 1
  , r = idx*2 + 2
  , largest = idx;

  if (l < size && arr[l] > arr[largest])largest = l;

  if (r < size && arr[r] > arr[largest])largest = r;

  if (largest != idx){
    swap(arr[largest], arr[idx]);
    heapify(arr, size, largest);
  }
  
}

template<class T>
void heapSort(T* arr, size_t size){
  
  // build the max-heap
  for (int i = size/2 - 1; i >= 0; i--) // start from the mid; to make sure that the current node does have a children.
    heapify(arr, size, i);
  // extract elements from the tree one-by-one
  for (int i = size - 1; i >= 0; i--){

    swap(arr[0], arr[i]);

    heapify(arr, i, 0);
  }
}

int main() {

  int arr[] = {6, 3, 2, 9, 9, 10, 2, 23, -13, -4};
  size_t size = sizeof(arr)/sizeof(arr[0]);

  heapSort(arr, size);

  for (size_t i = 0; i < size; i++)cout << arr[i] << ' ';

  return 0;
}
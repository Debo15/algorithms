#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
void selectionSort(T* arr, size_t size){
  
  for (size_t i = 0; i < size; i++){
    size_t minimum_idx = i;
    for (size_t j = i+1; j < size; j++){
      if (arr[j] < arr[minimum_idx])
        minimum_idx = j;
    }
    swap(arr[i], arr[minimum_idx]);
  }
}

int main() {

  int arr[] = {6, 3, 2, 9, 9, 10, 2, 23, -13, -4};
  size_t size = sizeof(arr)/sizeof(arr[0]);

  selectionSort(arr, size);

  for (size_t i = 0; i < size; i++)cout << arr[i] << ' ';

  return 0;
}
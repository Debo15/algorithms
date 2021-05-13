#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<class T>
void bubbleSort(T* arr, size_t size){
  for (size_t i = 0; i < size; i++){
    for (size_t j = i+1; j < size; j++){
      if (arr[i] > arr[j])swap(arr[i], arr[j]);
    }
  }
}

int main() {
  int arr[] = {6, 3, 2, 9, 9, 10, 2, 23, -13, -4};
  size_t size = sizeof(arr)/sizeof(arr[0]);
  bubbleSort(arr, size);
  for (size_t i = 0; i < size; i++)cout << arr[i] << ' ';
  return 0;
}
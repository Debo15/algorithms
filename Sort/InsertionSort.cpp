#include <iostream>

using namespace std;

template<class T>
void insertionSort(T* arr, size_t size){
  
  for (size_t i = 1; i < size; i++){
    T cur = arr[i];
    int j = i-1;
    while (j >= 0 && arr[j] > cur){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = cur;
  }
}

int main() {
  // worst case senario o(n^2)
  int arr[] = {6, 3, 2, 9, 9, 10, 2, 23, -13, -4};
  size_t size = sizeof(arr)/sizeof(arr[0]);

  insertionSort(arr, size);

  for (size_t i = 0; i < size; i++)cout << arr[i] << ' ';

  return 0;
}
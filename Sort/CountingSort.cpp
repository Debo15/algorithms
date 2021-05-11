#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void countingSort(int *arr, const size_t size){
  
  int upperBound = *max_element(arr, arr + size);
  int lowerBound = *min_element(arr, arr + size);
  
  int range = upperBound - lowerBound + 1; // K
  vector<int> count(range);// Frequncy Array


  for (size_t i = 0; i < size; i++)
    count[arr[i] - lowerBound]++;

  for (size_t i = 1; i < (size_t)range; i++)
    count[i] += count[i-1];

  vector<int> sorted(size); // copy of the array but sorted one

  for (size_t i = 0; i < size; i++) // sorting the copy(sorted) depends on the counters
    sorted[--count[arr[i] - lowerBound]] = arr[i];
  

  for (size_t i = 0; i < size; i++)arr[i] = sorted[i];

}

int main() {
  int arr[] = {6, 3, 2, 9, 9, 10, 2, 23, -13, -4};
  size_t size = sizeof(arr)/sizeof(arr[0]);
  countingSort(arr, size);
  for (size_t i = 0; i < size; i++)cout << arr[i] << ' ';
  return 0;
}
#include "bits/stdc++.h"

using namespace std;

// https://usaco.guide/gold/divisibility?lang=cpp#prime-factorization

const int MAX_N = (int)1e6;

int max_div[MAX_N + 5];

// O(MAX_N*log(MAX_N))
void constructMaxDiv(){
  for (int i = 2; i <= MAX_N; i++){
    if (max_div[i] != 0)continue;
    for (int j = i; j <= MAX_N; j += i)
      max_div[j] = i;
  }
}


int main() {
  constructMaxDiv();

  int n;
  cin >> n;

  vector<int> a(n);

  // 1 < a[i] <= 1e6
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n; i++){
    cout << a[i] << ":";
    while (a[i] != 1){
      int maxDiv = max_div[a[i]];
      while (a[i] % maxDiv == 0){
        cout << " " << maxDiv;
        a[i] /= maxDiv;
      }
    }
    cout << '\n';
  }
}

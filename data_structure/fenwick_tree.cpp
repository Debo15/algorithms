#include<iostream>
#include<vector>

using namespace std;

template<class T>
class fenwick_tree {
  vector<T> BIT;

public:

  fenwick_tree(int n) {
    BIT.resize(n);
  }

  void update(int idx, int value) {
    while (idx < N) {
      BIT[idx] += value;
      idx += idx & -idx;
    }
  }

  T operator[](int idx) {
    T res = 0;
    while (idx > 0) {
      res += BIT[idx];
      idx -= idx & -idx;
    }
    return res;
  }
};

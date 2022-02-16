#include<iostream>
#include<vector>

using namespace std;

template<class T>
class fenwick_tree {
  vector<T> BIT;
  int n;
public:

  fenwick_tree(int n) {
    BIT.resize(n+5);
    this->n = n+5;
  }

  void update(int idx, T value) {
    while (idx < n) {
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

template<class T>
class range_fenwick_tree {
  fenwick_tree<T> M, C;

public:
  range_fenwick_tree(int n) : M(n), C(n){};

  void update(int l, int r, T val) {
    M.update(l, val);
    M.update(r + 1, -val);
    C.update(l, -val * (l - 1));
    C.update(r + 1, val * r);
  }

  T operator[](int idx) {
    return idx * M[idx] + C[idx];
  }
};

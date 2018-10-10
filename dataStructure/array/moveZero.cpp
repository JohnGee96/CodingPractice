// Problem: Move all zeros in an array to the left 
//          while maintaining the order of non-zero elements
#include <iostream>

using namespace std;

void move_zeros_to_left(int a[], int n) {
  int read_ptr = n, write_ptr = n;
  int zero_cnt = 0;
  while (read_ptr >= 0) {
      if (a[read_ptr] != 0) {
          a[write_ptr] = a[read_ptr];
          --write_ptr;
      }
      else
          ++zero_cnt;
      --read_ptr;
  }
  for (int i=0; i<zero_cnt; ++i)
    a[i] = 0;
}

int main() {
    int a[] = {0, 1, 2, 6, 0, 2, 1, 0};
    int len = sizeof(a) / sizeof(int);

    for (int i=0; i<len; ++i)
        cout << a[i] << ' ';
    cout << '\n';

    move_zeros_to_left(a, len - 1);

    for (int i=0; i<len; ++i)
        cout << a[i] << ' ';
    cout << '\n';

    return 0;
}
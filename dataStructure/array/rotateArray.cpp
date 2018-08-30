// Problem: Given an array of n integers, rotate the array by k elements. k can be NEGATIVE.
// Solution:
//  1. Rotate entire array of n elements
//  2. Rotate first (m + k) % m elements
//  3. Rotate last m - k elements

#include <iostream>
#include <vector>

using namespace std;

// Surprisingly not as effcient as the trivial swap w/ temp var
void xorSwap(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

void swap(int& a, int&b) {
    int temp = a;
    a = b;
    b = temp;
}

void reverse(vector<int>& a, int start, int end) {
    while (start < end) {
        // cout << a[start] << ' ' <<  a[end] << '\n';
        swap(a[start], a[end]);
        ++start;
        --end;
    }
}

void rotate(vector<int>& a, int k) {
    int len = a.size();
    // normalize rotation index
    k = k % len;
    reverse(a, 0, len - 1);                   // 1. Reverse entire array
    reverse(a, 0, ((len + k) % len) - 1);     // 2. Reverse first (m + k) % m elements
    reverse(a, ((len + k) % len), len - 1);   // 3. Reverse the rest
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    rotate(a, 1);
    for (int i=0; i<a.size(); ++i)
        cout << a[i] << ' ';
    cout << '\n';

    a = {1, 2, 3, 4};
    rotate(a, 2);
    for (int i=0; i<a.size(); ++i)
        cout << a[i] << ' ';
    cout << '\n';

    a = {1, 2, 3, 4};
    rotate(a, -2);
    for (int i=0; i<a.size(); ++i)
        cout << a[i] << ' ';
    cout << '\n';

    return 0;
}
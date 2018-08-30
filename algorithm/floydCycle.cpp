// Problem in short:
//      Find the number of distinct values in a potentially cyclic sequence
// Problem Link:
// https://www.hackerrank.com/challenges/bitset-1/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define f(S, P, Q) ((S * P + Q) & 0x7FFFFFFF) // mod 2^31
typedef unsigned long UNLONG;
using namespace std;


int main() {
    int n, s, p, q;
    cin >> n >> s >> p >> q;
    s = s & 0x7FFFFFFF; // mod 2^31
        
    UNLONG turtle = s;
    UNLONG hare = s;
    int iter_cnt = 1;
    
    hare = f(hare, p, q); // move hare ptr one step ahead
    while (turtle != hare) {
        if (iter_cnt >= n) {
            cout << iter_cnt << endl;
            return 0;
        }
        turtle = f(turtle, p, q);
        hare = f(hare, p, q);
        hare = f(hare, p, q);
        iter_cnt++;
    };
    
    int non_cyclic_leng = 0;
    turtle = s;
    while (turtle != hare) {
        turtle = f(turtle, p, q);
        hare = f(hare, p, q);
        non_cyclic_leng++;
    }
    
    int cycle_leng = 1;
    turtle = f(hare, p, q);
    while (turtle != hare) {
        turtle = f(turtle, p, q);
        cycle_leng++;
    }
   
    cout << non_cyclic_leng + cycle_leng << endl;
    return 0;
}
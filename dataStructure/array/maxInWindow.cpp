// PROBLEM: Given a large array of integers and a window of size w, 
//          find current maximum in the window as the window slides through the entire array

// We can reduce the complexity of the previous solution by using a doubly linked list 
// (or a vector) where we can insert/delete at both ends. Notice that at Step 2 in the above
// example, when we get the newest element 3 in the window it is greater than all existing
// elements in the window (2, -5) and, in this case, the elements 2 and -5 can be safely 
// removed from the data structure holding the window. This property is critical for achieving
// a linear time solution of the problem. Here is the basic algorithm we will use to get a 
// better runtime.

// Window size is w and array size is n
// Iterate the first w elements of array; and for each element in the array, do the following:
// 1. remove elements from the tail of window (list) that are smaller than or equal to the current element
// 2. push current element at the tail of window

// The above step will ensure that the maximum of first w elements is at the head of linked list and it can be printed
// Run through remaining elements of the array and for each element do the following:
// 1. remove all elements from the tail of window that are smaller than or equal to the current element
// 2. remove the element at head if its index no longer falls in current window
// 3. push the current element at the tail of window
// 4. current max is at head and can be printed

#include <vector>
#include <iostream>
using namespace std;

void find_max_sliding_window(vector<int>& v, int window_size) {
    // window contains the index of original array's indices
    vector<int> window;
    if (window_size > v.size()) {
        cout << '\n';
        return;
    }
    // initialize the window subarray
    for (int i=0; i<window_size; ++i) {
        while (!window.empty() && v[i] >= v[window.back()]) {
            window.pop_back(); // remove content in the window if the new value is bigger
        }
        window.push_back(i);
    }

    cout << v[window.front()] << ' ';

    int w_start = 1;
    int w_end = window_size + 1;
    for (; w_end<v.size(); ++w_end) {
        // remove content outside the current window
        // cout << w_start << ' ' << w_end << '\n';
        if (!window.empty() && window.front() < w_start) {
            window.erase(window.begin());
        }
        while (!window.empty() && v[w_end] >= v[window.back()]) {
            window.pop_back(); // remove content in the window if the new value is bigger
        }
        window.push_back(w_end);
        cout << v[window.front()] << ' ';
        ++w_start;
    }
    cout << '\n';
    return;
}

int main(int argc, const char * argv[])
{
    vector<int> x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(int i=0; i<x.size(); ++i)
        cout << x[i] << ' ';
    cout<<endl;

    find_max_sliding_window(x, 3);

    x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::reverse(x.begin(), x.end());
    
    for(int i=0; i<x.size(); ++i)
        cout << x[i] << ' ';
    
    cout<<endl;
    
    find_max_sliding_window(x, 3);

    x = {10, 6, 9, -3, 23, -1, 34, 56, 67, -1, -4, -8, -2, 9, 10, 34, 67};
    std::reverse(x.begin(), x.end());
    
    for(int i=0; i<x.size(); ++i)
        cout << x[i] << ' ';
    
        cout<<endl;
    
    find_max_sliding_window(x, 3);

        return 0;
}
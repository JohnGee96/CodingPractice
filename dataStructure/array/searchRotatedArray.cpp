#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &v, int key, int start, int end) {
    int mid;
    // cout << end << mid << '\n';
    while (start <= end) {
        mid = start + ((end - start) / 2);
        if (key == v[mid])
            return mid;
        else if (key < v[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int binary_search_rotated(vector<int>& v, int key) {
    int mid;
    int start = 0;
    int end = v.size() - 1;
    while (start <= end) {
        mid = start + ((end - start) / 2);
        if (v[start] <= v[mid]) { // is first half sorted?
            // is key inside the sorted half?
            if (key >= v[start] && key <= v[mid]) {
                end = mid;
                return binary_search(v, key, start, end);
            }
            // search the unsorted half
            else {
                start = mid;
            }
        }
        else {
            // is key inside the other sorted half?
            if (key >= v[mid] && key <= v[end]) {
                start = mid;
                return binary_search(v, key, start, end);
            }
            else {
                end = mid;
            }
        }
    } 
    return -1; // returns -1 if not found
}

int main(int argc, char* argv[]) {
    vector<int> v1 = {6, 7, 1, 2, 3, 4, 5};
  
    cout<<"Key(3) found at: "<<binary_search_rotated(v1, 3)<<endl;
    cout<<"Key(6) found at: "<<binary_search_rotated(v1, 6)<<endl;
    
    vector<int> v2 = {4, 5, 6, 1, 2, 3};
    
    cout<<"Key(3) found at: "<<binary_search_rotated(v2, 3)<<endl;
    cout<<"Key(6) found at: "<<binary_search_rotated(v2, 6)<<endl;  
    return 0;  
  }
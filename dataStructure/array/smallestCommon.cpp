#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& v, int key) {
    int mid;
    int start = 0;
    int end = v.size() - 1;
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


int find_least_common_number(vector<int>& a1,
                             vector<int>& a2,
                             vector<int>& a3) {
    int commonNum;
    int p1 = 0;
    int a1_iter = a1.size();
    while (p1 < a1_iter) {
        cout << "looping" << '\n';
        commonNum = a1[p1];
        if (binary_search(a2, commonNum) != -1 && binary_search(a3, commonNum) != -1) {
            cout << "found it " << commonNum << '\n';
            return commonNum;
        }
        ++p1;
    }
    return -1;
}



int main() {
    vector<int> a1 = {1, 3, 9};
    vector<int> a2 = {2, 4, 6, 7, 9, 9};
    vector<int> a3 = {0, 1, 2, 9, 100};

    cout << "LCN: " << find_least_common_number(a1, a2, a3) << '\n'; 

    a1 = {1, 3, 3};
    a2 = {2, 4, 6, 7, 9, 9};
    a3 = {0, 1, 2, 9, 100};

    cout << "LCN: " << find_least_common_number(a1, a2, a3) << '\n';

    a1 = {1};
    a2 = {2, 4, 6, 7, 9, 9};
    a3 = {0, 2, 9, 100};

    cout << "LCN: " << find_least_common_number(a1, a2, a3) << '\n'; 

    a1 = {};
    a2 = {2, 4, 6, 7, 9, 9};
    a3 = {0, 2, 9, 100};

    cout << "LCN: " << find_least_common_number(a1, a2, a3) << '\n'; 
}
#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& v, int key, int start, int end) {
    int mid;
    while (start <= end) {
        mid = start + ((end - start ) / 2);
        if (key == v[mid])
            return mid;
        else if (key < v[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int find_low_index(vector<int>& v, int key) {
    int start = 0;
    int end = v.size() - 1;
    int pos = binary_search(v, key, start, end);
    if (pos != -1) {
        // search the lower half
        while (start < end) {
            end = pos - 1;
            pos = binary_search(v, key, start, end);
            if (pos == -1) {
                pos = end + 1;
                break;
            }
        }
    }
    return pos;
}

int find_high_index(vector<int>& v, int key) {
    int start = 0;
    int end = v.size() - 1;
    int pos = binary_search(v, key, start, end);
    if (pos != -1) {
        // search the higher half
        while (start < end) {
            start = pos + 1;
            pos = binary_search(v, key, start, end);
            if (pos == -1) {
                pos = start - 1;
                break;
            }
        }
    }
    return pos;
}

int main() {
    int low, high;
    int keys[] = {3, 2, 4, 5, 0};
    int testCases = sizeof(keys) / sizeof(int);
    vector<int> v = {1, 2, 3, 3, 3, 3, 3, 4, 5, 5};
    for (int i=0; i< v.size(); ++i)
        cout << v[i] << ' ';
    cout << '\n';
    for (int i=0; i < testCases; ++i) {
        low = find_low_index(v, keys[i]);
        high = find_high_index(v, keys[i]);
        cout << "key: " << keys[i] << " low: " << low << " high: " << high << '\n';
    } 
    return 0;
}
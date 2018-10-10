// Problem: determine if there are any two integers in the array sum to the given value

/**
 * Solution:
 * 1. Use a hash set to store location of every element in the array
 * 2. For each a[i] search counterpart n - a[i] in the hash set
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

// find_sum_of_two function return true if
// there are two values in array who
// sum to value and returns false otherwise
pair<int,int> find_sum_of_two(vector<int>& A, int sum) {
    unordered_set<int> found_values;
    unordered_set<int>::iterator search_result;
    pair<int,int> result(-1, -1);
    for (int& a: A) found_values.insert(a); // Initialize hash set
    for (int& a: A) {
        int counterpart = sum - a;
        search_result = found_values.find(counterpart);
        if (search_result != found_values.end()) {
            result.first = a;
            result.second = *search_result;
            return result;
        }
    }
    cout << "No value found\n"; 
    return result;
}


int main() {
    vector<int> v = {2, 1, 8, 4, 7, 3};
    int sum = 11;
    pair<int,int> result = find_sum_of_two(v, sum);

    cout << "Sum: " << sum << " = " << result.first << " + " << result.second << '\n';
}
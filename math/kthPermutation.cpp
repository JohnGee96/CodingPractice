// Find kth permutation
// Given a set of n elements find their kth permutation.

#include <vector>
#include <iostream>
#include <cmath>

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n-1);
}

std::string find_kth_permutation(
    std::vector<char>& v,
    int k) {
    
    int dict_size = v.size();
    int total_perm = factorial(dict_size);
    if (k < 1 || k > total_perm) {
        std::cout << "Error: Invalid rank: " << k 
                  << ". Total permutations: " << total_perm << '\n';
        return "";
    }

    if (dict_size == 1) {
        return std::string(1, v[0]);
    }

    int selected_index = int(k / dict_size);
    char c = v[selected_index];
    v.erase(v.begin() + selected_index); // Destructive method
    return c + find_kth_permutation(v, k - selected_index * (dict_size - 1));
}

int main() {
    std::vector<char> v = {'1','2','3'};
    std::string result = find_kth_permutation(v, 4);
    std::cout << result << '\n';
    
    // for (char& c: v)
    //     std::cout << c << ' ';
    // std::cout << '\n';
} 
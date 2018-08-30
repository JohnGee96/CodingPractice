// Problem in short:
//      Determine how many shifts in insertion sorting a list of numbers
// Problem Link:
// https://www.hackerrank.com/challenges/insertion-sort/problem
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


vector<int> merge(vector<int> left, vector<int> right, long int & cnt) {
    int l_elem, r_elem;
    vector<int> result;
    vector<int>::iterator it_left = left.begin();
    vector<int>::iterator it_right = right.begin();
    vector<int>::iterator l_end = left.end();
    vector<int>::iterator r_end = right.end();
    while ((it_left != l_end) && (it_right != r_end)) {
        l_elem = *it_left;
        r_elem = *it_right;
        if (l_elem <= r_elem) {
            result.push_back(l_elem);
            ++it_left;
        } else {
            result.push_back(r_elem);
            ++it_right;
            cnt = cnt + l_end - it_left;
        }
    }
    while (it_left != l_end) {
        result.push_back(*it_left);
        ++it_left;
    }
    while (it_right != r_end) {
        result.push_back(*it_right);
        ++it_right;
    }
    return result;
}


vector<int> mergesort(vector<int> arr, long int &cnt) {
    int size = arr.size();
    if (size > 1) {
        std::size_t const middle = size / 2;
        // merge sort left array
        vector<int> l (arr.begin(), arr.begin() + middle);
        vector<int> r (arr.begin() + middle, arr.end());
        vector<int> left = mergesort(l, cnt);
        vector<int> right = mergesort(r, cnt);
        
        arr = merge(left, right, cnt);
    }
    return arr;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }
            
        long int cnt = 0;
        vector<int> result = mergesort(arr, cnt);
        
        // for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
        //     cout << ' ' << *it;
        // }
            
        fout << cnt << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

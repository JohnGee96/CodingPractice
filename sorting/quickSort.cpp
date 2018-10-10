// Problem: implement quick sort

/* Algorithm Overview:
 *
 * Select a pivot element from the array. We can pick the first element or a random element.
 * (Partition) Comparing with the pivot and reorder smaller values to left and larger to right of the pivot.
 * Applying the above steps, recursively sort the sublists on the right and left sides of the pivot.
 *
 */
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

/**
 * Range: [low, high)
 */
int randint(int low, int high) {
    srand(time(NULL));
    return rand() % (high - low) + low;
}

/**
 * Hoare’s Partition 
 */
int partition(int a[], int start, int end, int pivot_index) {
    // cout << "Partition: start - " << start << " end - " <<  end << '\n';
    int len = end - start + 1;
    swap(a[start], a[pivot_index]);     // bring pivot to the start of the segment
    assert(pivot_index >= start && pivot_index <= end);
    int pivot = a[start];
    int low = start;
    int high = end;
    while (low < high) {
        while (low <= high && a[low] <= pivot) low++;
        while (a[high] > pivot) high--;
        if (low < high)
            swap(a[low], a[high]);
    }
    a[start] = a[high];
    a[high] = pivot; 
    // cout << "pivot index: " << low << '\n';
    return high;
}

/**
 * @param start - the starting index of the array segment to be sorted
 * @param end - the ending index
 */
void quick_sort_recur(int a[], int start, int end) {
    if (start < end) {
        int pivot_index = randint(start, end); // select a random pivot
        pivot_index = partition(a, start, end, pivot_index);
        quick_sort_recur(a, start, pivot_index - 1);
        // cout << "Start to recur the right size " << pivot_index+1 << ' ' << end << '\n'; 
        quick_sort_recur(a, pivot_index + 1, end);
    }
}

void quick_sort(int a[], int size){
    quick_sort_recur(a, 0, size - 1);
}

int main() {
    int a1[] = {12, -1, 5, 20, 23, 1, 2, -3, 0};
    int len1 = sizeof(a1) / sizeof(int);

    for (int i=0; i<len1; ++i)
        cout << a1[i] << ' ';
    cout << '\n';

    quick_sort(a1, len1);

    cout << "After sorting: ";

    for (int i=0; i<len1; ++i)
        cout << a1[i] << ' ';
    cout << '\n';

    int a2[] = {0, 0, 1, 1, 2};
    int len2 = sizeof(a2) / sizeof(int);
    
    for (int i=0; i<len2; ++i)
        cout << a2[i] << ' ';
    cout << '\n';

    quick_sort(a2, len2);
    cout << "After sorting: ";

    for (int i=0; i<len2; ++i)
        cout << a2[i] << ' ';
    cout << '\n';

    return 0;
}

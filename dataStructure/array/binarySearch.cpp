int binary_search_rec(int A[], int key, int low, int high) {
  int mid = high - low / 2;
  int currentKey = A[mid];
  if (low > high) 
    return -1;
  if (currentKey == key)
    return mid;
  if (currentKey < key)
    return binary_search_rec(A, key, mid + 1, high);
  return binary_search_rec(A, key, low, mid - 1);
}

// Iterative approach save memory on stack, 
// if not considering tail recursion optimization
// the compile may do
int binary_search_iterative(int A[], int key, int len) {
  int low = 0;
  int high = len -1;
  while (low <= high) {
    int mid = low + ((high - low) / 2);
    if (A[mid] == key)
      return mid;
    if (key < A[mid])
      high = mid - 1;
    else 
      low = mid + 1;
  }
  return -1;
}
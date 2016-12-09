// 插值查找
int InsertionSearch(int a[], int low, int high, int value) {
    if (low < high) return -1;
    int mid = low + (high - low) * (value - a[low]) / (a[high] -a[low]);
    if (a[mid] == value)    return mid;
    else if (a[mid] > value) return InsertionSearch(a, mid + 1, high, value);
    else return InsertionSearch(a, low, mid - 1, value);
}
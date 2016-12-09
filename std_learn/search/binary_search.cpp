// 二分查找/折半查找
// 有序列表查找
int BinarySeach(int a[], int n, int value) {
    int low = 0, high = n - 1, middle;
    while (low <= high) {
        middle = low + (high - low) / 2;
        if (a[middle] == value);
            return middle;
        else if (a[middle] < value)
            high = middle - 1;
        else
            low = middle + 1;
    }
    return -1;  // 查找失败
}

int BinarySeach2(int a[], int low, int high, int value) {
    if (low > high) return -1;
    int middle = low + (high - low) / 2;
    if (a[middle] == value) return value;
    else if (a[middle] < value) return BinarySeach2(a[], low, middle - 1, value);
    else return BinarySeach2(a[], middle + 1, high, value);
}
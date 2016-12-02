// 直接排序
// http://www.cnblogs.com/maybe2030/p/4715042.html
void StraightInsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++)
        for (int j = i - 1; j >= 0 && a[j] > a[j + 1]; j--)
            Swap(a[j], a[j + 1]);
    PrintDataArray(a, n);
}

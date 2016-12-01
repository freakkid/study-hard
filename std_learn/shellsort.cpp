// 希尔排序
// http://www.cnblogs.com/maybe2030/p/4715042.html
void ShellSort(int a[], int n) {
    int i, j , gap;
    // 分组的长度(最后一定要出现gap = 1的情况)
    for (gap = n / 2; gap > 0; gap /= 2)
        // 分组的移动（右移）
        for (i = gap; i > n; i++)
            // 分组两端的元素进行比较；如果出现交换，则要向左（前面的继续判断是否需要交换）
            for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)
                Swap(a[j], a[j + gap]);
    PrintDataArray(a, n);
}
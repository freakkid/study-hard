/* 直接选择排序
   http://www.cnblogs.com/maybe2030/p/4715042.html
   1）初始时，数组全为无序区a[0, ... , n-1], 令i=0;
　　2）在无序区a[i, ... , n-1]中选取一个最小的元素与a[i]交换，交换之后a[0, ... , i]即为有序区；
　　3）重复2），直到i=n-1，排序完成。
*/

void StrightSelectionSort(int a[], int n) {
    int minindex = 0;
    for (int i = 0; i < n - 1; i++) {
        minindex = i;
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[minindex])
                minindex = j;
        Swap(a[i], a[minindex]);
    }
    PrintDataArray(a, n);
}
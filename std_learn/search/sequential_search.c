//  顺序列表优化
// a[1..n]
int SequentialSearch(int *a, int n, int key) {
    int i = n;
    a[0] = key; // 设置哨兵
    while (a[i] != key) {
        --i;
    }
    return i;
}
// 斐波那契查找
// http://blog.csdn.net/yunzhongguwu005/article/details/9341761
#include <memory>

const int max_size = 20;    // 斐波那契数组长度
void Fibonacci(int *F) {
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i < max_size; i++)
        F[i] = F[i - 1] + F[i - 2];
}

void FibonacciSearch(int a[], int n, int value) {
    int F[max_size];
    Fibonacci(F);

    int low = 0, high = n - 1, k = 0;
    while (n > F[k] - 1)
        --k;
    
    int *tmp = new int[F[k] - 1];
    memcpy(tmp, a, sizeof(int) * n);    // 新开一个数组，数值与a相同
    for (int i = n; i < max_size; i++)  // 不满的用a[n - 1]补全
        tmp[i] = a[n - 1];
    
    while (low <= high) {
        int mid = low + F[k - 1] - 1;   // 找出分隔的下标
        if (F[mid] == value) {
            delete []tmp;
            if (mid <= n - 1)
                return mid;
            else              // mid - 1说明是补全数值 
                return n - 1;
        }
        else if (F[mid] < value) {
            k -= 2;
            low = mid + 1;
        }
        else {
            k -= 1;
            high = mid - 1;
        }
    }
    delete []tmp;
    return -1;
}
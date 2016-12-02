#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
void Swap(T&a, T&b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// 随机打乱数组
void RandomArray(int a[], int n) {
    int index;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        index = rand() % (n - i) + i;
        if (index != i)
            Swap(a[i], a[index]);
    }
}

// 看这个Partitionn()就好
int Partition(int a[], int low, int high) {
    int left = low, right = high;                       // 左右扫描指针
    int pivotkey = a[low];                              // 用第一个记录作枢轴记录
    while (left < right) {
        while (left < right && a[right] > pivotkey)
            --right;
        while (left < right && a[left] <= pivotkey)
            ++left;
        if (left >= right)  break;
        Swap(a[right], a[left]);
    }
    Swap(a[right], a[low]);                             // 此时的right指针在left左侧
    return right; 
}

// 可以不去看
int Partition1(int a[], int low, int high) {
    int pivotkey = a[low];                      // 用第一个记录作枢轴记录
    while (low < high) {
        while (low < high && a[high] >= pivotkey)
            --high;
        Swap(a[low], a[high]);
        while (low < high && a[low] <= pivotkey)
            ++low;
        if (low >= high)  break;
        Swap(a[high], a[low]);
    }
    return low; 
}


void QSort(int a[], int low, int high) {
    int pivot;
    if (low < high) {
        pivot = Partition(a, low, high);
        QSort(a, low, pivot - 1);
        QSort(a, pivot + 1, high);
    }
}


void PrintDateArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main() {
    int a[9] = {90, 70, 80, 60, 10, 40, 50, 30, 20};
    RandomArray(a, 9);
    PrintDateArray(a, 9);
    QSort(a, 0, 9);
    PrintDateArray(a, 9);
}
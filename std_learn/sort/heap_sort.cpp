#include <iostream>
using namespace std;

/* 
  堆排序
  http://www.cnblogs.com/maybe2030/p/4715042.html#_label3
  1. 如何将n 个待排序的数建成堆?
  2. 输出堆顶元素后，怎样调整剩余n-1 个元素，使其成为一个新堆?
  http://www.benfrederickson.com/heap-visualization/
*/
template <typename T>
void Swap(T&a, T&b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// 第二个问题：如何调整成一个堆
// 以a[root]为关键字，调整a[root]~a[end]成为一个大顶堆
void HeapAdjusting(int a[], int root, int end) {
    int parent = root; // 父节点的下标
    int child = 2 * root + 1; // 左孩子的下标
    while (child < end) {
        // 找到左右两孩子节点中最小的节点下标
        if (child + 1 < end && a[child + 1] < a[child])
            ++child;
        // 如果父节点的值比子节点最小的值还小（或等于），
        // 那就说明父节点真的很小，下面就不用排序了 :D
        if (a[parent] <= a[child]) break;
        // 如果父节点的值大于子节点，
        // 那父节点就要和最小子节点交换了
        Swap(a[parent], a[child]);
        // 狡猾完成后，堆就往下移，继续排序
        parent = child;
        child = 2 * child + 1;
    }
}

// 堆排序问题一：如何初始化建堆？
void HeapBuilding(int a[], int n) {
    // 下标为0~(n-1)/2的点（有子节点的节点）需要调整变动，其他节点不用
    for (int i = n / 2; i >= 0; i--)
        HeapAdjusting(a, i, n);
}

// 堆排序
void HeapSort(int a[], int n) {
    HeapBuilding(a, n);
    for (int i = n - 1; i > 0; i--) {
        // 交换堆顶元素和最后一个元素
        Swap(a[0], a[i]);
        // 每次交换后都要进行调整
        HeapAdjusting(a, 0, i);
    }
}

void PrintDateArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main () {
    int a[9] = {90, 70, 80, 60, 10, 40, 50, 30, 20};
    HeapSort(a, 9);
    PrintDateArray(a, 9);
}
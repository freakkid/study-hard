#include <iostream>
using namespace std;

template <typename T>
void Swap(T&a, T&b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        bool allAreSorted = true; // 判断是否交换过数据
        for (int j = n - 2; j >= i; j--) {
            if(a[j] > a[j + 1]) {
                Swap(a[j], a[j + 1]);
                allAreSorted = false; // 若交换过
            }
        }
        if (allAreSorted)  break; // 未交换过，说明以及排序完成
    }
}

void BubbleSort1(int a[], int n) {
    for (int i = 1; i < n; i++) {
        bool allAreSorted = true; // 判断是否交换过数据
        for (int j = n - 1; j >= i; j--) {
            if(a[j - 1] > a[j]) {
                Swap(a[j], a[j - 1]);
                allAreSorted = false; // 若交换过
            }
        }
        if (allAreSorted)  break; // 未交换过，说明以及排序完成
    }
}

void BubbleSort2(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool allAreSorted = true; // 判断是否交换过数据
        for (int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                Swap(a[j], a[j + 1]);
                allAreSorted = false; // 若交换过
            }
        }
        if (allAreSorted)  break; // 未交换过，说明以及排序完成
    }
}

void PrintDataArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}
 
void test() {
    int a[9] = {90, 70, 80, 60, 10, 40, 50, 30, 20};
    BubbleSort(a, 9);
    PrintDataArray(a, 9);
}

void test1() {
    int a[9] = {90, 70, 80, 60, 10, 40, 50, 30, 20};
    BubbleSort1(a, 9);
    PrintDataArray(a, 9);
}

void test2() {
    int a[9] = {90, 70, 80, 60, 10, 40, 50, 30, 20};
    BubbleSort2(a, 9);
    PrintDataArray(a, 9);
}

int main() {
    // int a[11] = {1000, 90, 70, 80, 60, 10, 40, 50, 30, 20, 1000};
    // 可以用来判断是否越界
    test();
    test1();
    test2();
}
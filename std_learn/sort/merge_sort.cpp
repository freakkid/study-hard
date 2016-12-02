#include <iostream>
#include <cstdlib>
#define MAXSIZE 100
using namespace std;


// 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]
void Merge(int SR[], int TR[], int i, int m, int n) {
    int j, k, l;
    for (j = m + 1, k = i; i <= m && j <= n; k++) {
        if (SR[i] < SR[j])
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }
    if (i <= m) {
        for (l = 0; l <= m - i; l++)
            TR[k + l] = SR[i + l];              // 将剩余的sr[i..m]复制到TR
    }
    if (j <= n) {
        for (l = 0; l <= n - j; l++)
            TR[k + l] = SR[j + l];              // 将剩余的sr[j..n]复制到TR
    }
}

void Merge1(int SR[], int TR[], int s, int m, int t) {
    int i, j, k, l;
    for (i = s, j = m + 1, k = s; i <= m && j <= t; k++) {
        if (SR[i] < SR[j])
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }
    if (i <= m) {
        for (l = 0; l <= m - i; l++)
            TR[k + l] = SR[i + l];
    }

    if (j <= t) {
        for (l = 0; l <= t - j; l++)
            TR[k + l] = SR[j + l];
    }
}

void Merge2(int SR[], int TR[], int s, int m, int t) {
    int i = s, j = m + 1;
    for (int k = s; k <= t; k++) {
        if (i > m)              TR[k] = SR[j++];
        else if (j > t)         TR[k] = SR[i++];
        else if (SR[i] < SR[j]) TR[k] = SR[i++];
        else                    TR[k] = SR[j++];
    }
}

// 将SR[s..t]归并排序为TR1[s..t]
void MSort(int SR[], int TR1[], int s, int t) {
    int TR2[MAXSIZE + 1] = {0};
    if (s == t)
        TR1[s] = SR[s];
    else {
        int m = s + (t - s) / 2;    // 将SR[s..t]平分为SR[s..m]和SR[m+1..t]
        MSort(SR, TR2, s, m);       // 将SR[s..m]归并排序为有序的 TR2[s..m]
        MSort(SR, TR2, m + 1, t);   // 将 SR[m+1..t] 归并排序为有序的 TR2[m+1..t]
        Merge(TR2, TR1, s, m, t);   // 将 TR2[s..m] 和 TR2[m+1..t] 归并排序为 TR1[s..t]
    }
}


void MergeSort(int a[], int n) {
    MSort(a, a, 0, n - 1);
}

void PrintDateArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main() {
    //int a[9] = {90, 70, 80, 60, 10, 40, 50, 30, 20};
    int a[100] = {0};
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
        a[i] = rand() % 100;
    //RandomArray(a, 100);
    PrintDateArray(a, 100);
    MergeSort(a, 100);
    PrintDateArray(a, 100);
}

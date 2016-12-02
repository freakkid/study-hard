// http://blog.csdn.net/hitwhylz/article/details/9970451

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Max_ 10         // 数组个数
#define RADIX_10 10     // 0-9十个数字的序列大小
#define KEYNUM_31 10    // 关键字个数，int数据的位数


void ShowArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}

// 找到num的从低到高的第pod(1~32)位数据
int GetNumInPos(int num, int pos) {
    return num / (int)(pow(10, pos - 1)) % 10;
}

// pDataArray无序数组，iDataNum无序数据个数
void RadixSort(int *pDataArray, int iDataNum) {

    int *radixArrays[RADIX_10]; // 分别为0~9的序列空间
    for (int i = 0; i < 10; i++) {
        radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));
        radixArrays[i][0] = 0; //记录数据个数
    }
    // 从个位开始到31位
    for (int pos = 1; pos <= KEYNUM_31; pos++) {
        for (int i = 0; i < iDataNum; i++) {
            int num = GetNumInPos(pDataArray[i], pos);
            int index = ++radixArrays[num][0];          // 记录数据个数
            radixArrays[num][index] = pDataArray[i];    // 记录数据内容
        }
        for (int i = 0, j = 0; i < RADIX_10; i++) {     // 收集
            for (int k = 1; k <= radixArrays[i][0]; k++)
                pDataArray[j++] = radixArrays[i][k];    // 重新排序
            radixArrays[i][0] = 0;                      // 复位
        }
    }
    // 释放动态分配的内存
    for (int i = 0; i < 10; i++) {
        free(radixArrays[i]);
    }
}

int main() {
    int arr_test[Max_] = {3, 2, 5, 7, 3, 0, 9, 32, 21, 214};
    ShowArray(arr_test, Max_);
    RadixSort(arr_test, Max_);
    ShowArray(arr_test, Max_);
    return 0;
}

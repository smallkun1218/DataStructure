//
// Created by luck on 2021/9/12.
//
#include "iostream"
#include "Sort.h"

#include "ctime"
#include "cstdio"
#include "random"

using namespace std;

void swap(long &num1, long &num2) {
    long temp = num1;
    num1 = num2;
    num2 = temp;
}

int partition(long *r, int i, int j) {

    while (i < j) {
        while (i < j && r[i] <= r[j])
            j--;
        if (i < j){
            swap(r[i], r[j]);
        }
        while(i < j && r[i] <= r[j])
            i++;
        if (i < j){
            swap(r[i], r[j]);
        }
    }
    return i;
}

void QuickSort(long *r, int low, int high) {
    if (low < high){
        int post = partition(r, low, high);
        QuickSort(r, low, post - 1);
        QuickSort(r, post + 1, high);
    }
}


int main(){
    clock_t start,end;
    start = clock();
    long a[100000];

    for (long & i : a) {
        i=random();
    }
    QuickSort(a, 0, 100000-1);

    for (long & i:a) {
        printf("%ld ", i);
    }
    end=clock();
    printf("\n-------------------------\n程序运行时间为:%fs",(double)(end-start)/CLOCKS_PER_SEC);

}

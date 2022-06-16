//
// Created by luck on 2021/9/12.
//

#ifndef DATASTRUCTURE_SORT_H
#define DATASTRUCTURE_SORT_H

#endif //DATASTRUCTURE_SORT_H

class Sort {

public:
    static void InsertSort(int r[], int n);

    static void ShellSort(int r[], int n);

    static void BubbleSort(int r[], int n);

    static void QuickSort(int r[], int low, int high);

    static void SelectSort(int r[], int n);

    static void HeapSort(int r[], int n);
private:
    static void swap(int &num1, int &num2);

    static int partition(int r[], int i, int j);

    static void sift(int r[], int k, int end);
};

void Sort::swap(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void Sort::InsertSort(int r[], int n) {

    for (int i = 2; i <= n; ++i) {
        r[0] = r[i];
        int j = i - 1;
        while (r[0] < r[j]) {
            r[j + 1] = r[j];
            j--;
        }

        r[j + 1] = r[0];

    }
}

void Sort::ShellSort(int r[], int n) {
    for (int d = n / 2; d >= 1; d /= 2) {
        for (int i = d + 1; i <= n; ++i) {
            r[0] = r[i];
            int j = i - d;
            while (j > 0 && r[0] < r[j]) {
                r[j + d] = r[j];
                j -= d;
            }
            r[j + d] = r[0];
        }
    }
}

void Sort::BubbleSort(int *r, int n) {
    int exchange = n - 1;
    while (exchange) {
        int bound = exchange;
        exchange = 0;
        for (int j = 0; j < bound; ++j) {
            if (r[j] > r[j + 1]) {
                swap(r[j], r[j + 1]);
                exchange = j;
            }
        }
    }
}

int Sort::partition(int r[], int i, int j) {

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

void Sort::QuickSort(int *r, int low, int high) {
    if (low < high){
        int post = partition(r, low, high);
        QuickSort(r, low, post - 1);
        QuickSort(r, post + 1, high);
    }
}

void Sort::SelectSort(int *r, int n) {
    for (int i = 1; i < n; ++i) {
        int min  = i;
        for (int j = i+1; j <= n; ++j) {
            if (r[j] < r[min]){
                min = j;
            }
        }
        if (min != i){
            swap(r[min], r[i]);
        }
    }
}

void Sort::sift(int *r, int k, int end) {
    int i = k, j = i * 2;
    while (j <= end){
        if (j < end && r[j] < r[j+1]){
            j++;
        }
        if (r[i] < r[j]){
            swap(r[i], r[j]);
        }
        i = j;
        j = i*2;
    }
}

void Sort::HeapSort(int *r, int n) {
    for (int i = n/2; i >= 1; --i) {
        sift(r, i, n);
    }
    for (int k = 1; k < n; ++k) {
        swap(r[1], r[n - k + 1]);
        sift(r, 1, n-k);
    }
}
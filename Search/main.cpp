//
// Created by luck on 2021/9/13.
//

#include "iostream"
#include "cstdio"
using namespace std;

#include "Search.h"

int main(){

    int num[] {8, 2, 2, 1, 3, 4, 5, 6, 7, 9, 10, 2, 1};
    auto * biSortTree = new BiSortTree(num, 13);
    biSortTree->inOrder();
    cout << biSortTree->deleteBST(1) << endl;
    biSortTree->inOrder();


    return 0;
}
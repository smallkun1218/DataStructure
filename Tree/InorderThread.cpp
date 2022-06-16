//
// Created by luck on 2021/8/24.
//

#include "bits/stdc++.h"

using namespace std;

typedef struct node {
    char data;
    int lTag, rTag;
    struct node *lChild, *rChild;
} BinThrNode, *pBinThrTree;

void CreatTree(pBinThrTree &T) {
    char ch = (char)getchar();

    if (ch == '#') {
        T = nullptr;
    } else {
        T = new BinThrNode;
        T->data = ch;
        CreatTree(T->lChild);
        CreatTree(T->rChild);
    }
}


void InThread(pBinThrTree p) {
    static pBinThrTree pre = nullptr;

    if (p == nullptr) {
        return;
    }
    InThread(p->lChild);
    if (p->lChild == nullptr) {
        p->lTag = 1;
        p->lChild = pre;
    }
    if (pre != nullptr && pre->rChild == nullptr) {
        pre->rChild = p;
        pre->rTag = 1;
    }
    pre = p;
    InThread(p->rChild);
}

pBinThrTree next(pBinThrTree p) {
    pBinThrTree q;
    if (p->rTag == 1)
        q = p->rChild;
    else {
        q = p->rChild;
        while (q->lTag == 0)
            q = q->lChild;
    }
    return q;
}

void InOrder(pBinThrTree root) {
    pBinThrTree p;
    if (root == nullptr)
        return;
    p = root;
    while (p->lTag == 0)
        p = p->lChild;
    printf("%c", p->data);
    while (p->rChild != nullptr) {
        p = next(p);
        printf("%c", p->data);
    }
    printf("\n");
}

void perOrder(pBinThrTree root) {
    stack<pBinThrTree> s;
    pBinThrTree p = root;
    while (p != nullptr || !s.empty()) {
        while (p != nullptr) {
            cout << p->data;
            s.push(p);
            p = p->lChild;
        }
        if (!s.empty()) {
            p = s.top();
            s.pop();
            p = p->rChild;
        }
    }
    cout << endl;
}


typedef struct {
    pBinThrTree ptr;
    int flag; //1表示第一次出栈，2表示第2次出栈
} element;

void postOrder(pBinThrTree root) {
    stack<element> s;
    pBinThrTree p = root;
    element elem;
    while (p != nullptr || !s.empty()) {
        if (p != nullptr) {
            elem.ptr = p;
            elem.flag = 1;
            s.push(elem);
            p = p->lChild;
        }else{
            elem = s.top();
            s.pop();
            p = elem.ptr;
            if(elem.flag == 1){
                elem.flag = 2;
                s.push(elem);
                p = p->rChild;
            }else{
                cout << p->data;
                p = nullptr;
            }
        }
    }
    cout << endl;
}

int main() {

    freopen("input.txt", "r", stdin);

    pBinThrTree T;

    CreatTree(T);
    perOrder(T);

    postOrder(T);

    InThread(T);
    InOrder(T);

    return 0;
}
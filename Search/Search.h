//
// Created by luck on 2021/9/13.
//

#ifndef DATASTRUCTURE_SEARCH_H
#define DATASTRUCTURE_SEARCH_H

#endif //DATASTRUCTURE_SEARCH_H

int BinSearch(int arr[], int key, int low, int high) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] > key) {
            return BinSearch(arr, key, low, mid - 1);
        } else {
            return BinSearch(arr, key, mid + 1, high);
        }
    } else {
        return -1;
    }
}

typedef struct BiNode {
    int data;
    BiNode *lChild, *rChild;
} BiNode;

class BiSortTree {
private:
    BiNode *root;
public:
    BiSortTree(int array[], int length);

    ~BiSortTree() { release(root); }

    BiNode *searchBST(int key) { return searchBST(root, key); }

    bool deleteBST(int key) { return deleteBST(root, key); }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }

    BiNode *f() {
        return root;
    }

private:
    void insertBST(BiNode *&bt, int key);

    void release(BiNode *bt);

    void inOrder(BiNode *bt);

    bool deleteBST(BiNode *&bt, int key);

    void deleteNode(BiNode *&bt);

    BiNode *searchBST(BiNode *bt, int key);
};

void BiSortTree::insertBST(BiNode *&bt, int key) {
    if (bt == nullptr) {
        bt = new BiNode;
        bt->data = key;
        bt->rChild = nullptr;
        bt->lChild = nullptr;
    } else if (bt->data < key) {
        insertBST(bt->rChild, key);
    } else {
        insertBST(bt->lChild, key);
    }
}

BiSortTree::BiSortTree(int *array, int length) {
    root = nullptr;
    for (int i = 0; i < length; ++i) {
        insertBST(root, array[i]);
    }
}

void BiSortTree::inOrder(BiNode *bt) {
    if (bt != nullptr) {
        inOrder(bt->lChild);
        printf("%d ", bt->data);
        inOrder(bt->rChild);
    }
}

BiNode *BiSortTree::searchBST(BiNode *bt, int key) {
    if (bt == nullptr) {
        return nullptr;
    } else {
        if (key == bt->data) {
            return bt;
        } else if (key < bt->data) {
            return searchBST(bt->lChild, key);
        } else {
            return searchBST(bt->rChild, key);
        }
    }
}


bool BiSortTree::deleteBST(BiNode *&bt, int key) {
    if (bt == nullptr) {
        return false;
    } else {
        if (bt->data == key) {
            deleteNode(bt);
        } else if (key < bt->data) {
            return deleteBST(bt->lChild, key);
        } else {
            return deleteBST(bt->rChild, key);
        }
        return true;
    }
}

void BiSortTree::deleteNode(BiNode *&bt) {
    auto p = bt;
    if (bt->lChild == nullptr && bt->rChild == nullptr) {
        bt = nullptr;
    } else if (bt->rChild == nullptr) {
        bt = bt->lChild;
    } else if (bt->lChild == nullptr){
        bt = bt->rChild;
    }else{
        auto parent = bt;
        auto pre = bt->lChild;
        while(pre->rChild){
            parent = pre;
            pre = pre->rChild;
        }
        bt->data = pre->data;
        if (bt!=parent){
            parent->lChild = pre->rChild;
        }else{
            parent->lChild = pre->lChild;
        }
        delete pre;
        return ;
    }
    delete p;
}
//
// Created by luck on 2021/11/22.
//
#include<stdio.h>
#include<stdlib.h>




void InOrder(BiTree T){
    if(T!=NULL){
        PreOrder(T->lchild);
        printf("%c",T->data);
        PreOrder(T->rchild);
    }
}

void PostOrder(BiTree T){
    if(T!=NULL){
        PreOrder(T->lchild);
        PreOrder(T->rchild);
        printf("%c",T->data);
    }
}


int main(){
//    BiTree T;
//    InitList(T);
//    CreateBiTree(T);
//    printf("\n先序遍历为");
//    PreOrder(T);
//    printf("\n中序遍历为");
//    InOrder(T);
//    printf("\n后序遍历为");
//    PostOrder(T);
    return  0;
}
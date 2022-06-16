//
// Created by luck on 2021/11/22.
//
#include "cstdio"
#include "cstdlib"

#include<stdio.h>
#include<stdlib.h>
#include "queue"
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void InitList(BiTree &L){
    L=(BiTree)malloc(sizeof(BiTNode));
    L->lchild=NULL;
    L->rchild=NULL;
}

void CreateBiTree(BiTree &T){
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
        T==NULL;
    else{
        T=(BiTree)malloc(sizeof(BiTNode));
        if(T==NULL)
            return;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void PreOrder(BiTree T){
    if(T!=NULL){
        printf("%c",T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

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
    BiTree T;
    InitList(T);
    CreateBiTree(T);
    printf("\n先序遍历为");
    PreOrder(T);
    printf("\n中序遍历为");
    InOrder(T);
    printf("\n后序遍历为");
    PostOrder(T);


    return 0;
}
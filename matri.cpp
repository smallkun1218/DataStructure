#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INIT_SIZE 100
#define INCREMENT 10
typedef struct student{
    char num[20];
    char name[20];
    char six[3];
    char pnum[20];
    char qq[20];
}ElemType;

typedef struct{
    ElemType*elem;
    int length;
    int listsize;
}SqList;


void InitList(SqList &L){
    L.elem=(ElemType*)malloc(INIT_SIZE*sizeof(ElemType));
    if(!L.elem)
        exit(1);
    L.length=0;
    L.listsize=INIT_SIZE;
}

int  ListInsert(SqList &L,int i,ElemType e){
    ElemType*newbase,*q,*p;
    if(i<1||i>L.length+1)
        return 0;
    if(L.length>=L.listsize){
        if(!(newbase=(ElemType*)realloc(L.elem,(L.listsize+INCREMENT)*sizeof(ElemType))))
            exit(-1);
        L.elem=newbase;
        L.listsize+=INCREMENT;
    }
    q=L.elem+i-1;
    for(p=L.elem+L.length-1;p>=q;--p)
        *(p+1)=*p;
    *q=e;
    ++L.length;
    return 1;
}

int ListDelete(SqList &L,int i,ElemType &e){
    ElemType *p,*q;
    if(i<1||i>L.length)
        return 0;
    q=L.elem+i-1;
    e=*q;
    for(p=L.elem+L.length-1;p>q;++q){
        *q=*(q+1);
    }
    L.length--;
    return 1;
}
void input(ElemType &s){
    scanf("%s%s%s%s%s",s.num,s.name,s.six,s.pnum,s.qq);
}

void outprint(ElemType s){
    printf("%s\t%s\t%s\t%s\t%s\n",s.num,s.name,s.six,s.pnum,s.qq);
}

void ListTraverse(SqList L,void(*vi)(ElemType)){
    ElemType *p;
    int i;
    p=L.elem;
    for(i=1;i<=L.length;i++)
        vi(*p++);
    printf("\n");
}

int LocateElem(SqList L,ElemType e,int(*equal)(ElemType,ElemType)){
    ElemType *p;
    int i=1;
    p=L.elem;
    for(i;i<=L.length;i++){
        if(equal(L.elem[i],e)==1)
            return i+1;
    }
    return 0;
}

int equals(ElemType a,ElemType b){
    if(strcmp(a.name, b.name) != 0)
        return 1;
    else
        return 0;
}

int compare(ElemType *a,ElemType *b){

    return a->name[0] - b->name[0];
}

void swap(ElemType & a, ElemType & b){
    ElemType t;
    t = a;
    a = b;
    b = a;
}

void sort(SqList &L){
    for (int i = 0; i < L.length - 1; ++i) {
        for (int j = 0; j < L.length - 1 - i; ++j) {
            if (compare(L.elem+j,L.elem+j+1)>0){
                swap(L.elem[j], L.elem[j+1]);
            }
        }
    }
}

int main(){
    SqList A;
    ElemType e;
    int i,j,n,m;
    char s;
    printf("请输入学生位数\n");
    scanf("%d",&n);
    printf("请输入学生学号，姓名，性别，电话，QQ\n");
    InitList(A);
    for(i=1;i<=n;i++){
        input(e);
        ListInsert(A,i,e);
    }
    printf("将学生按姓名排序\n");
    sort(A);
    ListTraverse(A,outprint);
//		ListTraverse(A,outprint);
//		printf("请输入需要删除的学生\n");
//		scanf("%d",&m);
//		ListDelete(A,m,e);
//		ListTraverse(A,outprint);
//		printf("请输入需要查找的学生学号\n");
//		scanf("%s",&e);
//		LocateElem(A,e,equals);
//		outprint(e);



}
//
// Created by luck on 2022/4/14.
//

#include <stdio.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkedList;

/* 初始化单链表 */
void InitList_L(LinkedList& L){
	L = new LNode;
	L->next = NULL;
}

void InitList_L(LinkedList& L, int a[], int n){
	L = new LNode;
	L->next = NULL;
	for (int i = n - 1; i >= 0; i--){
		LinkedList s = new LNode;
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

/* 销毁单链表 */
void DestroyList_L(LinkedList& L){
	LinkedList p = L;
	LinkedList q;
	while (p){
		q = p;
		p = p->next;
		delete q;
	}
	L = NULL;
}

/* 检查单链表是否为空 */
int isEmpty(LinkedList L){
	return L->next == NULL;
}

/* 遍历单链表 */
void Show_L(LinkedList L){
	LinkedList p = L->next;
	printf("开始输出链表：\n");
	while (p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n链表输出完毕！\n\n");
}

/* 求单链表的长度 */
int ListLength_L(LinkedList L){
	if (!L){
		printf("链表未初始化！\n\n");
		return -1;
	}
	LinkedList p = L->next;
	int count = 0;
	while (p){
		count++;
		p = p->next;
	}
	return count;
}

/* 单链表中按值查找元素返回其位置 */
int LocateElem_L(LinkedList L, ElemType e){
	LinkedList p = L->next;
	int location = 1;
	while (p){
		if (p->data == e) return location;
		else{
			p = p->next;
			location++;
		}
	}
	return 0;
}

/* 向单链表的第i个位置上插入元素 */
void ListInsert_L(LinkedList L, int i, ElemType x){
	if (i < 1){
		printf("插入位置非法！\n\n");
		return;
	}
	LinkedList p = L;
	int j = 0;
	while (p && j < i - 1){
		p = p->next;
		j++;
	}
	if (!p){
		printf("插入位置非法！\n\n");
		return;
	}
	else{
		//TODO:编写代码实现链表第i个位置的插入
		LinkedList pNew = new LNode;
		pNew->data = x;
		pNew->next = p->next;
		p->next = pNew;
		return;
	}
}

/* 删除单链表的第i个位置上的元素 */
void ListDelete_L(LinkedList L, int i){
	if (i < 1){
		printf("删除位置非法！\n\n");
		return;
	}
	LinkedList p = L;
	int j = 0;
	while (p && j < i - 1){
		p = p->next;
		j++;
	}
	if (!p||!p->next){
		printf("删除位置非法！\n\n");
		return;
	}
	else{
		//TODO:编写代码实现链表第i个结点的删除
		LinkedList q = p->next;
		p->next = p->next->next;
		delete q;

		return;
	}
}

/* 从单链表中删除元素 */
void DeleteElem_L(LinkedList L, ElemType x){
	LinkedList pre = L;
	while (pre->next && pre->next->data != x){
		pre = pre->next;
	}
	if (!pre->next){
		printf("元素%d在链表中不存在！\n\n", x);
		return;
	}
	else{
		LinkedList q = pre->next;
		pre->next = q->next;
		delete q;
	}
}

int main(){
	LinkedList L;
	int a[5] = { 1, 2, 3, 4, 5 };
	InitList_L(L, a, 5);
	printf("链表长度为：%d\n", ListLength_L(L));
	Show_L(L);
	printf("在位置3上插入元素6：\n");
	ListInsert_L(L, 3, 6);
	Show_L(L);
	printf("删除位置4上的元素：\n");
	ListDelete_L(L, 4);
	Show_L(L);
	printf("删除元素6：\n");
	DeleteElem_L(L, 6);
	Show_L(L);
	printf("删除元素8：\n");
	DeleteElem_L(L, 8);
	Show_L(L);
	return 0;
}
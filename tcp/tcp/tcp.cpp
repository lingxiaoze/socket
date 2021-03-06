#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include "stdafx.h"

using namespace std;
void quicksort(int a[], int low, int high)
{
	int i = low, j = high;
	int pivot = a[low];
	if (low < high)
	{
		while (i < j)
		{
			while (i<j&&a[j]>=pivot)j--;
			if(i<j)a[i++] = a[j];
			while (i < j&&a[i] <= pivot)i++;
			if(i<j)a[j--] = a[i];
		}
		a[i] = pivot;
		quicksort(a, low, i - 1);
		quicksort(a, i + 1, high);
	}


}
typedef struct BTree1 *postion;
typedef postion BTree;
struct BTree1 {
	int data;
	BTree lchild, rchild;
};

BTree createTree(BTree bt,bool isRoot)
{
	int ch;
	if (isRoot)printf("root :");
	scanf("%d", &ch);
	if (ch != '#')
	{
		bt = new BTree1;
		isRoot = 0;
		bt->data = ch;
		bt->lchild = NULL;
		bt->rchild = NULL;
		printf("%d lchild is :",bt->data);
		bt->lchild = createTree(bt->lchild, isRoot);
		printf("%d rchild is :", bt->data);
		bt->rchild = createTree(bt->rchild, isRoot);
	}
	return bt;
}

void levelordertree(BTree bt)
{
	queue<int >q;
	q.push(bt);
	while (!q.empty())
	{
		BTree ptr = q.front();
		cout << ptr->data << " ";
		q.pop();
		if (ptr->lchild != NULL)q.push(ptr->lchild);
		if (ptr->rchild != NULL)q.push(ptr->rchild);
	}
}

int main()
{
	/*int b[10] = { 2,5,7,1,9,0,4,3,8,6 };
	quicksort(b,0, 9);
	for (int i = 0; i < 10; i++)
	printf("b[%d]=%d\n", i, b[i]);*/
	BTree bt;
	bt = createTree(bt, 1);
	cout << "tree is :" << endl;
	levelordertree(bt);
	return 0;
}



// Heap_Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void Heapify(int Heap[],int i,int n)	//n la so phan tu con lai trong Heap
{
	if (i*2+1<=n-1)
	{
		int child1 = i * 2 + 1, child2 = i * 2 + 2, tmp = child1;
		if (Heap[child2] > Heap[child1] && i * 2 + 2 <= n - 1) tmp = child2;
		if (Heap[i]< Heap[tmp])
		{
			swap(Heap[i], Heap[tmp]);
			Heapify(Heap, tmp, n);
		}
	}
}
void Heap_sort(int Heap[],int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--) Heapify(Heap, i, n);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(Heap[i], Heap[0]);
		Heapify(Heap, 0, i);
	}
}
int main()
{
	int a[7] = { 10,15,9,8125,109,27,675 };
	Heap_sort(a, 7);

	for (int i = 0; i < 7; i++) cout << a[i] << " ";
	system("pause");
}


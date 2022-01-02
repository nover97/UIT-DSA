#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct NODE
{
	int info;
	NODE *pNext;
};
struct LIST
{
	NODE *pHead;
	NODE *pTail;
};

NODE *CreateNode(int x)
{
	NODE *p;
	p = new NODE;
	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddTail(LIST &L, NODE *p)
{
	if (L.pHead == NULL)
		L.pHead = p;
	else
		L.pTail->pNext = p;
	L.pTail = p;
}

void CreateEmptyList(LIST &L)
{
	L.pHead = L.pTail = NULL;
}
void CreateList(LIST &L)
{
	NODE *p;
	int x, n;
	cout << "Nhap so phan tu:" << endl;
	cin >> n;
	cout << "Nhap " << n << " so:" << endl;
	while (n-- > 0)
	{
		cin >> x;
		p = CreateNode(x);
		AddTail(L, p);
	}
}
NODE *TachHead(LIST &k)
{
	if (!k.pHead)
		return NULL;
	NODE *p = k.pHead;
	k.pHead = p->pNext;
	p->pNext = NULL;
	if (!k.pHead)
		k.pTail == NULL;
	return p;
}
void Partition(LIST &k, LIST &k1, LIST &k2)
{
	CreateEmptyList(k1);
	CreateEmptyList(k2);
	int z = 1;
	NODE *p;
	while (k.pHead)
	{
		p = TachHead(k);
		if (z)
		{
			AddTail(k1, p);
			z = 0;
		}
		else
		{
			AddTail(k2, p);
			z = 1;
		}
	}
}
void Merge_2_Sorted(LIST &k, LIST &k1, LIST &k2)
{
	CreateEmptyList(k);
	NODE *p;
	int a1, a2;
	while (k1.pHead && k2.pHead)
	{
		a1 = k1.pHead->info, a2 = k2.pHead->info;
		if (a1 <= a2)
			p = TachHead(k1);
		else
			p = TachHead(k2);
		AddTail(k, p);
	}
	if (!k1.pHead)
	{
		if (!k.pHead)
			k.pHead = k2.pHead;
		else
			k.pTail->pNext = k2.pHead;
		k.pTail = k2.pTail;
		CreateEmptyList(k2);
	}
	else
	{
		if (!k.pHead)
			k.pHead = k1.pHead;
		else
			k.pTail->pNext = k1.pHead;
		k.pTail = k1.pTail;
		CreateEmptyList(k1);
	}
}
void mergesort_ascending(LIST &k)
{
	if (k.pHead == k.pTail)
		return;
	LIST k1, k2;
	CreateEmptyList(k1);
	CreateEmptyList(k2);
	Partition(k, k1, k2);
	mergesort_ascending(k1);
	mergesort_ascending(k2);
	Merge_2_Sorted(k, k1, k2);
}
int length(NODE *p)
{
	int i = 0;
	while (p)
	{
		i++;
		p = p->pNext;
	}
	return i;
}

void PrintList(NODE *p)
{
	if (p == NULL)
		cout << "Empty List.";
	else
	{
		cout << "Length: " << length(p) << endl;
		while (p)
		{
			cout << p->info << " ";
			p = p->pNext;
		}
	}
}

int main()
{
	LIST L;
	CreateEmptyList(L);
	CreateList(L);
	mergesort_ascending(L);
	PrintList(L.pHead);

	return 0;
}

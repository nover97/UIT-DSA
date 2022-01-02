#include <iostream>
using namespace std;
typedef struct NODE
{
	int info;
	NODE *pNext;
} node;
struct LIST
{
	NODE *pHead;
	NODE *pTail;
};
NODE *CreateNode(int x)
{
	NODE *p = new NODE;
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
	if (k.pHead == NULL)
		return NULL;
	NODE *p = k.pHead;
	k.pHead = p->pNext;
	p->pNext = NULL;
	if (k.pHead == NULL)
		k.pTail = NULL;
	return p;
}
void Partition(LIST &k, LIST &k1, NODE *&pv, LIST &k2)
{
	pv = TachHead(k);
	int a = pv->info;
	while (k.pHead != NULL)
	{
		NODE *p = TachHead(k);
		if (p->info <= a)
			AddTail(k1, p);
		else
			AddTail(k2, p);
	}
}
void Join(LIST &k, LIST &k1, NODE *&pv, LIST &k2)
{
	k.pHead = k1.pHead;
	k.pTail = k1.pTail;
	k1.pHead = k1.pTail = NULL;
	AddTail(k, pv);
	k.pTail->pNext = k2.pHead;
	if (k2.pTail != NULL)
		k.pTail = k2.pTail;
	k2.pHead = k2.pTail = NULL;
}
void quicksort_ascending(LIST &k)
{
	if (k.pHead == k.pTail)
		return;
	LIST k1, k2;
	CreateEmptyList(k1);
	CreateEmptyList(k2);
	NODE *pv = new NODE;
	Partition(k, k1, pv, k2);
	quicksort_ascending(k1);
	quicksort_ascending(k2);
	Join(k, k1, pv, k2);
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
	quicksort_ascending(L);
	PrintList(L.pHead);

	return 0;
}

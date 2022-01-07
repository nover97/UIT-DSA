/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>
using namespace std;
struct node
{
	int i4;
	node *next;
};
typedef struct list
{
	node *pHead, *pTail;
} LIST;
node *CreateNode(int x)
{
	node *p = new node;
	p->i4 = x;
	p->next = NULL;
	return p;
}
void CreateEmptyList(list &k)
{
	k.pHead = k.pTail = NULL;
}
void AddHead(list &k, node *p)
{
	if (!k.pHead)
		k.pHead = k.pTail = p;
	else
		p->next = k.pHead;
	k.pHead = p;
}
void AddTail(list &k, node *p)
{
	if (!k.pHead)
		k.pHead = k.pTail = p;
	else
		k.pTail->next = p;
	k.pTail = p;
}
void CreateList(list &k)
{
	int x;
	cout << "Insert number (-1 to stop): ";
	cin >> x;
	while (x != -1)
	{
		node *p = CreateNode(x);
		AddTail(k, p);
		cin >> x;
	}
}
void Print_Middle(list k)
{
	if (!k.pHead)
	{
		cout << "Empty List.";
		return;
	}
	if (k.pHead == k.pTail)
	{
		cout << k.pHead->i4;
		return;
	}
	node *fast, *slow;
	fast = slow = k.pHead;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		if (!fast)
		{
			cout << slow->i4;
			return;
		}
		slow = slow->next;
	}
	cout << slow->i4;
}
int main()
{
	LIST L;
	CreateEmptyList(L);

	CreateList(L);
	Print_Middle(L);

	return 0;
}

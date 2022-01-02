#include <iostream>
using namespace std;
struct Node
{
	int info;
	Node *Left, *Right;
	Node(int x)
	{
		this->info = x;
		Left = Right = NULL;
	}
};
typedef Node *Tree;
void push(Tree &k, int x)
{
	if (k)
	{
		if (x == k->info)
			return;
		if (x < k->info)
			push(k->Left, x);
		else
			push(k->Right, x);
	}
	else
		k = new Node(x);
}

// Input value to NODE
void CreateTree(Tree &k)
{
	cout << "Insert nodes (-1 to stop):" << endl;
	int x;
	cin >> x;
	while (x != -1)
	{
		push(k, x);
		cin >> x;
	}
}
void preOrder(Tree k)
{
	if (k)
	{
		cout << k->info << " ";
		preOrder(k->Left);
		preOrder(k->Right);
	}
}
void inOrder(Tree k)
{
	if (k)
	{
		inOrder(k->Left);
		cout << k->info << " ";
		inOrder(k->Right);
	}
}
void postOrder(Tree k)
{
	if (k)
	{
		postOrder(k->Left);
		postOrder(k->Right);
		cout << k->info << " ";
	}
}
void PrintTree(Tree k)
{
	if (!k)
		cout << "Empty Tree.";
	else
	{
		preOrder(k);
		cout << endl;
		inOrder(k);
		cout << endl;
		postOrder(k);
		cout << endl;
	}
}

// Đếm NODE trong TREE
int countNode(Tree k)
{
	static int count_all = 0;
	if (!k)
		return 0;
	else
	{
		int a = countNode(k->Left);
		int b = countNode(k->Right);
		count_all++;
	}
	return count_all;
}
// Đếm NODE chỉ có 1 con
int countNode_Half(Tree k)
{
	static int count_1 = 0;
	if (!k)
		return 0;
	else
	{
		int a = countNode_Half(k->Left);
		int b = countNode_Half(k->Right);
		if ((k->Left && !k->Right) || (k->Right && !k->Left))
			count_1++;
	}
	return count_1;
}

// Đếm NODE FULL (2 con hoặc 0 con)
int countNode_Full(Tree k)
{
	static int count_full = 0;
	if (!k)
		return 0;
	else
	{
		int a = countNode_Full(k->Left);
		int b = countNode_Full(k->Right);
		if ((k->Left && k->Right) || (!k->Left && !k->Right))
			count_full++;
	}
	return count_full;
}
void inOrder(Tree k, int &s)
{
	if (k)
	{
		s += k->info;
		inOrder(k->Left, s);
		inOrder(k->Right, s);
	}
}
int SumNode(Tree k)
{
	if (!k)
		return 0;
	int s = 0;
	inOrder(k, s);
	return s;
}
int main()
{
	Tree k;
	k = NULL;
	CreateTree(k);
	PrintTree(k);
	return 0;
}

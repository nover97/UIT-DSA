/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

#define MAXTABLESIZE 10000

struct NODE
{
	int key;
};
typedef NODE HASHTABLE[MAXTABLESIZE];

int TableSize;
int M;

int HF(int key)
{
	return key % M;
}
int HF_LinearProbing(int key, int i)
{
	return (HF(key) + i) % TableSize;
}
//###INSERT CODE HERE -
void CreateEmptyHash(HASHTABLE &k)
{
	cout << "Nhap M: ";
	cin >> M;
	cout << "\nNhap Table Size: ";
	cin >> TableSize;
	cout << endl;
	int i = -1;
	while (i++ < TableSize)
		k[i].key = -1;
}
int checkfull(HASHTABLE k, int size)
{
	if (size < TableSize)
		return 0;
	return 1;
}
void push(HASHTABLE &k, int x)
{
	int a = HF(x);
	if (k[a].key == x)
		return;
	if (k[a].key == -1)
		k[a].key = x;
	else
	{
		int i = 1;
	again:
		int a = HF_LinearProbing(x, i);
		if (k[a].key == x)
			return;
		if (k[a].key == -1)
			k[a].key = x;
		else
		{
			i++;
			goto again;
		}
	}
}

void CreateHashTable(HASHTABLE &k, int &size)
{
	CreateEmptyHash(k);
	int x;
	cout << "Insert number (-1 to stop): " << endl;
	cin >> x;
	size = 0;
	while (x != -1)
	{
		if (checkfull(k, size))
			return;
		push(k, x);
		size++;
		cin >> x;
	}
}
void Traverse(const HASHTABLE &H, const int &CurrentSize)
{
	for (int i = 0; i < TableSize; i++)
		cout << i << " --> " << H[i].key << endl;
}
int main()
{
	HASHTABLE H;
	int CurrentSize;

	CreateHashTable(H, CurrentSize);
	Traverse(H, CurrentSize);

	return 0;
}

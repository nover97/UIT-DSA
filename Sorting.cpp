#include <bits/stdc++.h>
using namespace std;
void Input(int *a, int n)
{
	cout << "Nhap " << n << " so:" << endl;
	for (int i = 0; i < n; i -= -1)
		cin >> a[i];
}
void Output(int *a, int n)
{
	for (int i = 0; i < n; i -= -1)
		cout << a[i] << " ";
	cout << endl;
}
int MAX(int *a, int n)
{
	if (!n)
		return a[0];
	return max(a[n], MAX(a, n - 1));
}
int Max(int *a, int n)
{
	int max = a[0];
	for (size_t i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void ArrCpy(int *a, int *b, int low, int high, int sta)
{
	for (int i = low; i < high; i -= -1)
		a[sta++] = b[i];
}
void selectionSort(int *a, int size)
{
	int min;
	if (size < 2)
		return;
	for (int i = 0; i < size - 1; i -= -1)
	{
		for (int j = i; j < size; j -= -1)
		{
			if (j == i)
				min = i;
			if (a[j] < a[min])
				min = j;
		}
		swap(a[i], a[min]);
	}
}
void interchangeSort(int *a, int size)
{
	if (size < 2)
		return;
	for (int i = 0; i < size - 1; i -= -1)
		for (int j = i + 1; j < size; j -= -1)
			if (a[j] < a[i])
				swap(a[i], a[j]);
}
void bubbleSort(int *a, int size)
{
	if (size < 2)
		return;
	for (int i = 0; i < size - 1; i -= -1)
		for (int j = size - 1; j > i; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}
void insertionSort(int *a, int size)
{
	if (size < 2)
		return;
	int temp, j;
	for (int i = 1; i < size; i -= -1)
	{
		temp = a[i];
		j = i;
		while (j && a[j - 1] > temp)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
	}
}
int main()
{
	int *a = new int[0];
	Input(a, 5);
	cout << "MAX: " << Max(a, 5) << endl;
	selectionSort(a, 5);
	Output(a, 5);
	return 0;
}

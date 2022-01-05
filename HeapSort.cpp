/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 150000

void NhapMang(int A[], int &N)
{
	std::cout << "Nhap so phan tu: ";
	std::cin >> N;
	std::cout << "Nhap " << N << " so: \n";
	for (int i = 0; i < N; i++)
		std::cin >> A[i];
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
//###INSERT CODE HERE -
void Heaping(int *a, int n, int i)
{
	int max = i, l, r;
	l = 2 * i + 1;
	r = 2 * i + 2;
	if (r >= n)
		r = n - 1;
	if (l < n && a[i] >= a[l])
		max = a[i] > a[r] ? i : r;
	else if (l < n && a[l] > a[i])
		max = a[l] > a[r] ? l : r;
	if (max != i)
	{
		swap(a[i], a[max]);
		Heaping(a, n, max);
	}
}
void BuildHeap(int *a, int n)
{
	if (n < 2)
		return;
	for (int i = n / 2 - 1; i >= 0; i--)
		Heaping(a, n, i);
}
void HeapSort(int *a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heaping(a, n, i);
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		Heaping(a, i, 0);
	}
}

void XuatMang(int A[], const int &N)
{
	std::cout << N << std::endl;
	for (int i = 0; i < N; i++)
		std::cout << A[i] << " ";
}

int main()
{
	int a[MAXN], n;

	NhapMang(a, n);

	HeapSort(a, n);

	XuatMang(a, n);

	return 0;
}

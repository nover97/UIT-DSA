
#include <iostream>
#include <climits>
using namespace std;
#define MAXN 150000

void NhapMang(int A[], int &N)
{
    cout << "Nhap so phan tu:" << endl;
    cin >> N;
    cout << "Nhap " << N << " so:" << endl;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void arrCpy(int *a, int *b, int h, int t, int j)
{
    for (int i = h; i <= t; i++)
        a[j++] = b[i];
}
void merge(int *a, int l, int mid, int r)
{
    if (l > r)
        return;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int *a1 = new int[n1];
    arrCpy(a1, a, l, mid, 0);
    int *a2 = new int[n2];
    arrCpy(a2, a, mid + 1, r, 0);
    int i, j, k;
    i = j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
            a[k++] = a1[i++];
        else
            a[k++] = a2[j++];
    }
    while (i < n1)
        a[k++] = a1[i++];
    while (j < n2)
        a[k++] = a2[j++];
}
void mergeSortRange(int input[], int from, int to)
{
    if (from < to)
    {
        int middle = (from + to) / 2;
        mergeSortRange(input, from, middle);
        mergeSortRange(input, middle + 1, to);
        merge(input, from, middle, to);
    }
}

void mergeSort(int input[], int n)
{
    mergeSortRange(input, 0, n - 1);
}

void XuatMang(int A[], const int &N)
{
    std::cout << "Length: " << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main()
{
    int a[MAXN], n;

    NhapMang(a, n);

    mergeSort(a, n);

    XuatMang(a, n);

    return 0;
}

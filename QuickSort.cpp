#include <iostream>
#define MAXN 150

void NhapMang(int A[], int &N)
{
    std::cout << "Nhap so phan tu:" << endl;
    std::cin >> N;
    std::cout << "Nhap " << n << " so:" << endl;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void XuatMang(int A[], const int &N)
{
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}
void hoanvi(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void quickSort(int *a, int h, int t)
{
    if (h >= t)
        return;
    int pv = a[t];
    int i = h, j = t;
    while (i <= j)
    {
        while (a[i] < pv)
            i++;
        while (a[j] > pv)
            j--;
        if (i <= j)
        {
            hoanvi(a[i], a[j]);
            i++;
            j--;
        }
    }
    quickSort(a, h, j);
    quickSort(a, i, t);
}
void quick_sort_ascending(int *a, int n)
{
    quickSort(a, 0, n - 1);
}
int main()
{
    int a[MAXN], n;

    NhapMang(a, n);

    quick_sort_ascending(a, n);

    XuatMang(a, n);

    return 0;
}

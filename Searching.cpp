#include <bits/stdc++.h>
using namespace std;

//Trả về vị trí của phần tử cần tìm trong mảng, không thấy thì return -1
int linearSearch(int x, int *a, int n) {
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return -1;
}

//BinarySearch và InterpolationSearch chỉ dùng cho mảng đã sắp xếp
int binarySearch(int x, int *a, int l, int r) {
    if (l > r)
        return -1;
    int mid = (r + l) / 2;
    if (a[mid] == x)
        return mid;
    if (a[mid] > x)
        return binarySearch(x, a, l, mid - 1);
    return binarySearch(x, a, mid + 1, r);
}
int interpolationSearch(int x, int *a, int l, int h) {
    if (l <= h && x >= a[l] && x <= a[h]) {
        int p = l + (((double)(h - l) / (a[h] - a[l])) * (x - a[l]));
        if (a[p] == x)
            return p;
        if (a[p] > x)
            return interpolationSearch(x, a, l, p - 1);
        return interpolationSearch(x, a, p + 1, h);
    }
    return -1;
}

int main() {
    int x, a[] = {-25, -2, 0, 6, 8, 12, 15, 27, 38, 40, 45, 49, 50, 53, 62};
    cout << "Insert a number: ";
    cin >> x;
    cout << "Linear Search: " << linearSearch(x, a, 15) << endl;
    cout << "Binary Search: " << binarySearch(x, a, 0, 14) << endl;
    cout << "Interpolation Search: " << interpolationSearch(x, a, 0, 14) << endl;
}
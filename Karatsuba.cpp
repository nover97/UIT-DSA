#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Ham lam cho hai chuoi bang nhau bang cach them '0' phia truoc chuoi ngan hon va tra ve do dai chuoi sau cung
int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0; i < len2 - len1; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
            str2 = '0' + str2;
    }
    return len1; // len1 = len2
}

// Ham cong hai chuoi bit tra ve ket qua dang chuoi bit
string addBitStrings(string first, string second)
{
    string result;
    int length = makeEqualLength(first, second); // Lam cho do dai hai chuoi bang nhau truoc khi cong
    int carry = 0;                               // Bien nho
    for (int i = length - 1; i >= 0; i--)
    { // Cong tat ca cac bit tung bit mot
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';
        int sum = (firstBit ^ secondBit ^ carry) + '0';
        result = (char)sum + result;
        // Neu 2 trong ba bien firstBit, secondBit, carry bang 1 thi carry bang 1
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }
    if (carry)
        result = '1' + result; // Neu tran them '1' o phia truoc
    return result;
}

// Ham nhan cac bit don cua hai chuoi a va b
int multiplyiSingleBit(string a, string b)
{
    return (a[0] - '0') * (b[0] - '0');
}

// Ham chinh de nhan hai chuoi bit X va Y,	Ket qua tra ve long int
long int multiply(string X, string Y)
{
    int n = makeEqualLength(X, Y); //Lam hai chuoi co do dai bang nhau, tra ve do dai 2 chuoi
    if (n == 0)
        return 0; // Dieu kien dung cua de quy
    if (n == 1)
        return multiplyiSingleBit(X, Y);
    int fh = n / 2;    // Do dai nua dau cua chuoi
    int sh = (n - fh); // Do dai nua sau cua chuoi
                       // Tach chuoi X thanh hai chuoi nua dau va nua cuoi
    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);
    // Tach chuoi y thanh hai chuoi nua dau va nua cuoi
    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);
    // De quy tinh toan ba phan co dau vao co n/2
    long int P1 = multiply(Xl, Yl);
    long int P2 = multiply(Xr, Yr);
    long int P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr));
    // Ket hop ba phan de lay ket qua cuoi cung
    return P1 * (1 << (2 * sh)) + (P3 - P1 - P2) * (1 << sh) + P2;
}

int main()
{
    cout << "1100 * 1010\t= " << multiply("1100", "1010") << endl;
    cout << "110 * 1010\t= " << multiply("110", "1010") << endl;
    cout << "1 * 1010\t= " << multiply("1", "1010") << endl;
    cout << "0 * 1010\t= " << multiply("0", "1010") << endl;
    cout << "111 * 1010\t= " << multiply("111", "1010") << endl;
    cout << "111 * 111\t= " << multiply("111", "111") << endl;
    cout << "11 * 11 \t= " << multiply("11", "11") << endl;
    cout << "1011010111 * 1011010111\t= " << multiply("1011010111", "1011010111") << endl;
    float a = sqrt(528529);
    cout << a << endl
         << a * a;
    return 0;
}

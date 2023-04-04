#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int prime = 101; // prime number for hash function

int valueOf(char ch)
{
    return (ch - '0');
}

bool check_characters(string T, string P, int s)
{
    int n = T.length();
    int m = P.length();
    for (int i = 0; i < m; i++)
    {
        if (P[i] != T[s + i])
            return false;
    }
    return true;
}

int int_pow(int x, int n)
{
    int result = 1;
    while (n)
    {
        if (n & 1)
            result *= x;
        x *= x;
        n >>= 1;
    }
    return result;
}

void rabin_karp_matcher(string T, string P)
{
    int n = T.length();
    int m = P.length();
    if (m > n) {
        cout << "Error: Pattern length is greater than text length." << endl;
        return;
    }
    int h = int_pow(prime, m - 1); // precompute the value of d^(m-1)
    int p = 0; // hash value of pattern
    int t = 0; // hash value of current window in text
    for (int i = 0; i < m; i++)
    {
        p = prime * p + valueOf(P[i]); // calculate hash value of pattern
        t = prime * t + valueOf(T[i]); // calculate hash value of first window in text
    }
    for (int s = 0; s <= n - m; s++)
    {
        if (p == t && check_characters(T, P, s))
            cout << "Pattern found at index " << s << endl;
        if (s < n - m)
            t = prime * (t - h * valueOf(T[s])) + valueOf(T[s + m]); // slide the window and recalculate hash value
    }
}

int main()
{
    string T, P;
    cout << "Enter text: ";
    getline(cin, T);
    cout << "Enter pattern: ";
    getline(cin, P);
    rabin_karp_matcher(T, P);
    return 0;
}

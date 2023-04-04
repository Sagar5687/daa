#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int char_to_value(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 10; // 10 to 35 for capital letters
    } else if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 36; // 36 to 61 for small letters
    } else {
        return ch-'0'; // invalid character
    }
}

bool check_characters(string T, string P, int s) {
    int m = P.length();
    for (int i = 0; i < m; i++) {
        if (P[i] != T[s+i+1]) {
            return false;
        }
    }
    return true;
}

void rabin_karp_matcher(string T, string P, int d, int q) {
    int n = T.length();
    int m = P.length();
    int h = (int) pow(d, m-1) % q;
    int p = 0;
    int t0 = 0;
    int hits[m];
    int l=0;
    for (int i = 0; i < m; i++) {
        p = (d*p + char_to_value(P[i])) % q;
        t0 = (d*t0 + char_to_value(T[i])) % q;
    }
    int spurious_hits = 0;
    for (int s = -1; s < n-m; s++) {
        if (p == t0) {
            if (check_characters(T, P, s)) {
                hits[l]=s+1;
                l++;
            } else {
                spurious_hits++;
            }
        }
        if (s < n-m) {
            t0 = (d * (t0 - char_to_value(T[s+1]) * h) + char_to_value(T[s+m+1])) % q;
            if (t0 < 0) {
                t0 += q;
            }
        }
    }
    cout << spurious_hits << endl;
    for(int i=0;i<l;i++)
    cout<<hits[i]<<endl;
}
int main()
{
    string T, P;
    int d,q;
    cin>>T>>P;
    cin>>d>>q;
    rabin_karp_matcher(T,P,d,q);
}

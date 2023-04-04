#include<iostream>
using namespace std;
#include<string>
#include<math.h>
int valueOf(char ch)
{
    return (ch-'0');
}

bool check_characters(string T, string P, int s)
{
    int n = T.length();
    int m = P.length();
    for(int i=0; i<m; i++)
    {
        if(P[i] != T[s+i])
            return false;
    }
    return true;
}

void rabin_karp_matcher(string T, string P, int d, int q)
{
    int i,s;
    int n = T.length();
    int m = P.length();
    int h = 1;
    int p = 0;
    int t0 = 0;

    for(i=0; i<m-1; i++)
    {
        h=(h*d)%q;
    }

    for(i=0;i<m;i++)
    {
        p=(d*p + valueOf(P[i]))%q;
        t0=(d*t0 + valueOf(T[i]))%q;
    }


    for(s=0;s<=n-m;s++)
    {
        if(p==t0)
        {
            if(check_characters(T,P,s))
            {
                cout<<s<<endl;
            }
        }
        if(s<n-m)
        {
            t0=(d*(t0-valueOf(T[s])*h)+valueOf(T[s+m]))%q;
            if(t0<0)
            {
                t0+=q;
            }
        }
    }
}
int main()
{
    string T, P;
    int d,q;
    cin>>T>>P;
    cin>>d>>q;
    rabin_karp_matcher(T,P,d,q);
}

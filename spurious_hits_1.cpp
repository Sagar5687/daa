#include<iostream>
using namespace std;
#include<string>
#include<math.h>
int valueOf(char ch)
{
    int a=ch-'0';
    // a is upper case
    if(a>=65 && a<=90)
    return a-55;
    // a is lowercase
    if(a>=97 && a<=122)
    return a-61;
    // a is regular number
    return a;
}
bool check_characters(string T, string P, int s)
{
    int n,m,i;
    n = T.length();
    m = P.length();
    for(i=0;i<m;i++)
    {
        if(P[i]!=T[s+i])
            return false;
    }
    return true;
}
void rabin_karp_matcher(string T, string P, int d, int q)
{
    int n, m, h, p, t0, i,s;
    n = T.length();
    m = P.length();
    p = 0;
    t0 = 0;
    for(i=0;i<m;i++)
    {
        p += (valueOf(P[i]));
        t0 += (valueOf(T[i]));
    }
    int spurious=0;
    int patterns[10];
    int no=0;
    for(s=0;s<=n-m;s++)
    {
        //cout<<p<<" "<<t0<<endl;
        if(p==t0)
        {
           if (check_characters(T,P,s)){
                patterns[no]=s;
                no++;
           }
           else if(check_characters(T,P,s)==false){
            spurious++;
           }
        }
            t0 = ((t0-valueOf(T[s]))+valueOf(T[s+m]));
        }
    cout<<spurious<<endl;
    for(i=0;i<no;i++)
    cout<<patterns[i]<<endl;
}
int main()
{
    string T, P;
    int d,q;
    cin>>T>>P;
    cin>>d>>q;
    rabin_karp_matcher(T,P,d,q);
}

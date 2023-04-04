Given a text T and a pattern P, implement the naive algorithm to print the non-overlapping positions of P in T. For example, if T is "aaaaaaaa" and pattern is "aa" then the code should print 0, 2, 4, 6 (programming indices - non-over lapping)
  
  naive algorithm to find patterns that are non-overlapping
#include<iostream>
using namespace std;
#include<string>
bool check_pattern(string T, string P, int s)
{
    int m = P.length(),i;
    for(i=0;i<m;i++)
    {
        if(P[i]!=T[s+i+1])
            return false;
    }
    return true;

}


void naive_string_matcher(string T, string P)
{
    int n,m,s,i;
    n = T.length();
    m = P.length();

    for(s=-1;s<=n-m-1;s++)
    {
        if (check_pattern(T,P,s)){
            cout<<s+1<<endl;
            s+=m-1;
        }
    }

}

int main()
{

    string T, P;
    cin>>T>>P;
    naive_string_matcher(T,P);
}

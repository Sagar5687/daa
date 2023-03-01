/*In matrix chain multiplication problem, given the number of matrices to be multiplied, write a C++ program to find the number of ways it may be parenthesized. For example, when there are three matrices A1, A2 and A3 there are two ways to parenthesize them. (A1(A2A3)) and ((A1A2)A3). If there are four matrices A1, A2, A3 and A4 then there are five ways to parenthesize as shown (A1(A2(A3A4))), (A1((A2A3)A4)), ((A1,A2)(A3A4)), ((A1(A2A3))A4), (((A1A2)A3)A4).

Input Format

First line contains the number of matrices in the chain, n

Output Format

Print the possible number of parenthesization*/


#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
int count_par(int n)
{
    int l,i,j,k,q;

    vector<vector<int> > m(n,vector<int>(n,0));
    for (i = 0; i < n; i++) 
        m[i][i] = 1;
    
    for(l=2;l<=n;l++)
    {
        for(i=0;i<=n-l;i++)
        {
            j = i+l-1;
            for(k=i;k<j;k++)
            {
                m[i][j] +=m[i][k]*m[k+1][j] ;

            }
        }
    }
    return m[0][n-1];
}


int main()
{    
    int n,i,j,a;
    cin>>n;
    int count=count_par(n);
    cout<<count<<endl;
}

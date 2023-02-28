/*Develop a top down dynamic programming algorithm to find minimum cost for matrix chain multiplication. Print the tables maintained by the algorithm. For example, when there are six matrices and the input given is 

7
30 35 15 5 10 20 25

M table should be printed as 

15750 7875 9375 11875 15125 
2625 4375 7125 10500 
750 2500 5375 
1000 3500 
5000 
S table should be printed as 
1 1 3 3 3 
2 3 3 3 
3 3 3 
4 5 
5 
Input Format

First line contains the number of matrices +1, n

Next line contains the dimensions of the matrices in the chain

Output Format

Print the mtable

Print the s table

Print the minimum cost*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainOrder(vector<int>& p, vector<vector<int>>& m,vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        return 0;
    }
    if (m[i][j] != -1) {
        return m[i][j];
    }
    m[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        int x=matrixChainOrder(p, m, s, i, k) + matrixChainOrder(p, m, s, k+1, j) + p[i-1]*p[k]*p[j];
        if(x<m[i][j]){
            m[i][j]=x;
            s[i][j]=k;
        }
    }
    return m[i][j];
}

int main() {
    int n;

    cin >> n;
    
    vector<int> p(n+1);

    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }
    
    vector<vector<int>> m(n+1, vector<int>(n+1, -1));
    vector<vector<int>> s(n+1, vector<int>(n+1, -1));
    int mincost = matrixChainOrder(p, m, s, 1, n);
    
    for(int i=1;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    
    for(int i=1;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
            cout<<s[i][j]<<" ";
        cout<<endl;
    }
    
    cout << m[1][n-1];
    
    return 0;
}

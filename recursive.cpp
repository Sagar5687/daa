/*
Matrix chain multiplication problem aims at finding the optimal way to parenthesize the matrix chain so that the number of multiplications (cost) will be minimum. The matrices are compatible for matrix multiplication so the number of columns in the ith matrix will be equal to number of rows in the (i+1)th matrix. Given dimension of ‘n’ matrices in the chain, write a recursive algorithm and code to find the minimum cost required to multiply the matrices in the chain. For example, if there are three matrices A1, A2, A3 and the dimension are 10 x 100, 100 x 5 and 5 x 50 respectively then input will 10, 100, 5, 50 and minimum cost will be 7500 when parenthesized as ((A1A2)A3).*/

#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
int matrix_chain_mul(int i, int j, vector<int> &p)
{
    int min_cost = INT_MAX,k,left_cost,right_cost,total_cost;    
    if(i==j)
        return 0;
    for(k=i;k<j;k++)
    {       
        left_cost = matrix_chain_mul(i,k,p);
        right_cost = matrix_chain_mul(k+1,j,p);
        total_cost = left_cost + right_cost + p[i-1] * p[k] * p[j];
        if(total_cost<min_cost)
        {
            min_cost = total_cost;
            
        }
    }
    return min_cost;
}

int main()
{
    int n,ele,i;
    vector<int> p;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        p.push_back(ele);
    }
cout<<matrix_chain_mul(1,n-1,p);
}

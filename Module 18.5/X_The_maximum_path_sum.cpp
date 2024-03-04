#include<bits/stdc++.h>
using namespace std;
int mat[101][101];
int n,m;
bool valid(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<m) return true;
    else return false;
}
int maxPath(int i,int j)
{
    if(i == n-1 && j== m-1)
    return mat[i][j];

    if(valid(i+1,j) && valid(i,j+1))
    {
        int op2 = maxPath(i, j + 1) + mat[i][j];
        int op1 = maxPath(i+1,j) + mat[i][j];
        return max(op1,op2);
    }
    if(valid(i+1,j))
    {
        return maxPath(i + 1, j) + mat[i][j];
    }
    if(valid(i,j+1))
    {
        return maxPath(i, j + 1) + mat[i][j];
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<maxPath(0,0);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int val[1001];
int Weight[1001];
const int maxN = 1001;
const int maxW = 1001;
int dp[maxN][maxW];
int knapsack(int n,int w)
{
    if (n == 0 || w == 0)
        return 0;
    
    if(dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (Weight[n-1] <= w)
    {
        int op1 = knapsack(n-1,w-Weight[n-1]) + val[n-1]; // if choosing
        int op2 = knapsack(n-1,w); // if not choosing

        return dp[n][w] = max(op1, op2);
    }
    else
    {
        int op2 = knapsack(n-1,w); // when the bag is not have enough space
        return dp[n][w] = op2;
    }
}
int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>Weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int w;
    cin >> w;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            dp[i][j] = -1;
        }
    }
    
    cout<<knapsack(n,w);
    return 0;
}
//Top Down Approach
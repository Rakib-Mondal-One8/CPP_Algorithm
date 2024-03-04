#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int Un_Knapsack(int val[], int w[], int s, int n)
{
    if (n == 0 || s == 0)
        return 0;
    if(dp[n][s] != -1)
    {
        return dp[n][s];
    }
    if (w[n - 1] <= s)
    {
        int op1 = Un_Knapsack(val, w, s - w[n - 1], n) + val[n-1];
        int op2 = Un_Knapsack(val, w, s, n - 1);
        return dp[n][s] = max(op1, op2);
    }
    else
    {
        return dp[n][s] = Un_Knapsack(val, w, s, n - 1);
    }
}
int main()
{
    int n;
    cin >> n;

    int val[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
        w[i] = i + 1;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << Un_Knapsack(val, w, n, n);
    return 0;
}
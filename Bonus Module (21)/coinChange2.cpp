#include <bits/stdc++.h>
using namespace std;
// int dp [1001][1001];
// int Un_knapsack(int w[],int s,int n)
// {
//     if(n == 0)
//     {
//         if(s==0)
//         {
//             return 0;
//         }
//         else
//         return INT_MAX - 1;
//     }
//     if(dp[n][s] != -1)
//         return dp[n][s] ;
//     if(w[n-1] <= s)
//     {
//         int op1 = Un_knapsack(w,s-w[n-1],n) + 1;
//         int op2 = Un_knapsack(w,s,n-1);

//         return dp[n][s] = min(op1, op2);
//     }
//     else
//     {
//         return dp[n][s] = Un_knapsack(w, s, n - 1);
//     }
// }
int main()
{
    int n;
    cin >> n;

    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int s;
    cin >> s;
    int dp[n + 1][s + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = INT_MAX - 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = min(dp[i][j - w[i - 1]]+1, dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // cout<<Un_knapsack(w,s,n);
    cout << dp[n][s];
    return 0;
}
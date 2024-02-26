#include <bits/stdc++.h>
using namespace std;

int weight[1005];
int val[1005];
// int maxVal = 0;
int dp[1004][1004];
int knapsack(int w, int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if(dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (weight[n - 1] <= w)
    {
        int op1 = knapsack(w - weight[n - 1], n - 1) + val[n-1];
        int op2 = knapsack(w, n - 1);

        return dp[n][w] = max(op1, op2);
    }
    else
        return dp[n][w] = knapsack(w, n - 1);
}
int main()
{
    int tCase;
    cin >> tCase;

    while (tCase--)
    {
        int n, w;
        cin >> n >> w;

        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                dp[i][j] = -1;
            }
        }
        int ans = knapsack(w, n);
        cout << ans << endl;
    }
    return 0;
}
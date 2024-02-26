#include <bits/stdc++.h>
using namespace std;
// Only return the cnt
// Code is as same as subset sum checking. But return the sum of op1 & op2
int arr[1004];
int dp[1005][1005];
int cnt_subset_sum(int arr[], int n, int s)
{
    if (n == 0)
    {
        if (s == 0)
            return 1;
        else
            return 0;
    }
    if(dp[n][s] != -1)
        return dp[n][s];
    if (arr[n - 1] <= s)
    {
        int op1 = cnt_subset_sum(arr, n - 1, s - arr[n - 1]);
        int op2 = cnt_subset_sum(arr, n - 1, s);

        return dp[n][s] = op1 + op2;
    }
    else
        return dp[n][s] = cnt_subset_sum(arr, n - 1, s);
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = -1;
        }
    }
    int Count = cnt_subset_sum(arr, n, sum);
    cout << Count << endl;
    return 0;
}
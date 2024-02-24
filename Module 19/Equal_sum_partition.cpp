#include <bits/stdc++.h>
using namespace std;
int arr[1005];
int dp[1005][1005];
bool Equal_sum_partition(int arr[], int n, int s)
{
    if(n==0)
    {
        if(s==0) return true;
        else return false;
    }
    if(dp[n][s] != -1)
        return dp[n][s];
    if (arr[n - 1] <= s)
    {
        bool op1 = Equal_sum_partition(arr, n - 1, s - arr[n - 1]);
        bool op2 = Equal_sum_partition(arr, n - 1, s);
        return dp[n][s] = op1 || op2;
    }
    else
        return dp[n][s] = Equal_sum_partition(arr, n - 1, s);
}
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            dp[i][j] = -1;
        }
    }
    if (sum % 2 == 0)
    {
        if (Equal_sum_partition(arr, n, sum / 2))
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
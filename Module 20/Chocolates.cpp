#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int>&arr,int n, int t)
{
    vector<vector<bool>> dp(n+1,vector<bool>(t+1,false));
    dp[0][0] = true;

    for(int i=1;i<=t;i++)
    {
        dp[0][i] = false;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=t;j++)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][t];
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int total = 0;
        vector<int>arr(n);
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            arr[i] = val;
            total += val;
        }

        if (total % 2 == 0)
        {
            if (subsetSum(arr,n, total / 2))
            {
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }        
    }

    return 0;
}
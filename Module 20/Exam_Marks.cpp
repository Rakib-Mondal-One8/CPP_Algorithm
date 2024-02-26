#include <bits/stdc++.h>
using namespace std;

bool WantedMarks(const vector<int> &arr,int n, int m)
{
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    // dp[0][0] = true;
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = true;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, obtained;
        cin >> n >> obtained;
        vector<int>arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        if (WantedMarks(arr,n, 1000 - obtained))
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// bool WantedMarks(const vector<int> &arr, int n, int m)
// {
//     vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

//     // Base case initialization
//     for (int i = 0; i <= n; ++i)
//         dp[i][0] = true;

//     // Bottom-up DP
//     for (int i = 1; i <= n; ++i)
//     {
//         for (int j = 1; j <= m; ++j)
//         {
//             if (arr[i - 1] <= j)
//             {
//                 dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
//             }
//             else
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     return dp[n][m];
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, obtained;
//         cin >> n >> obtained;
//         vector<int> arr(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         if (WantedMarks(arr, n, 1000 - obtained))
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();
    int dp[a.size() + 1][b.size() + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // cout << dp[n][m] << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int i=n;
    int j=m; // in longest common subsequence the maximum matched can be seen in the last index of the table
    string ans;
    while(i!=0 && j!=0)
    {
        if(a[i-1] == b[j-1])
        {
            ans+=a[i-1];
            i-=1;
            j-=1;
        }
        else if (dp[i-1][j] < dp[i][j-1])
        {
           j--;
        }
        else
            i-=1;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}
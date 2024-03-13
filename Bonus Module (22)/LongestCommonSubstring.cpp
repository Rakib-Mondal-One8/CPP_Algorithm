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
                dp[i][j] = 0;
            }
        }
    }
    // cout << dp[n][m] << endl;
    int mx = 0;
    int xi = 0;
    int xj = 0;
    // in longest common substring the common string can be found any where in table. longest substring is nothing but highest matched character count
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (dp[i][j] > mx)
            {
                mx = dp[i][j];
                xi = i;
                xj = j;
            }
        }
    }
    cout << mx << endl; // max size of substring

    string ans;
    while(xi != 0 && xj !=0)
    {
        if(dp[xi][xj] == 0)
            break;
        ans+= a[xi-1];
        xi--;
        xj--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}
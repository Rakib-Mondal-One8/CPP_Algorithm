#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n, x;
    cin >> n >> x;

    ll val[n];
    ll total = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> val[i];
        total += val[i];
    }
    bool dp[n + 1][total];
    dp[0][0] = true;
    for (ll i = 1; i <= total; i++)
    {
        dp[0][i] = false;
    }
    ll s1 = (x + total) / 2;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= total; j++)
        {
            if (val[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - val[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if (dp[n][s1] && abs(s1 - (total - s1)) == x)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
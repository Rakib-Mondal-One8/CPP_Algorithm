#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[100001];
ll result(ll arr[], int idx)
{
    if (idx < 0)
        return 0;
    if(dp[idx] != -1)
        return dp[idx];
    ll op1 = result(arr, idx - 2) + arr[idx];
    ll op2 = result(arr, idx - 1);

    return dp[idx] = max(op1,op2);
}
int main()
{
    int tCase;
    cin >> tCase;

    int i=1;
    while (i<=tCase)
    {
        ll n;
        cin >> n;
        memset(dp,-1,sizeof(dp));
        ll arr[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout<<"Case "<<i<<": "<<result(arr, n - 1)<<endl;
        i++;
    }
    return 0;
}
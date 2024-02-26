#include<bits/stdc++.h>
#define ll long long int
#define maxSum 20* 100000 + 5
using namespace std;
bool Dp[105][maxSum];
ll arr[105];
bool subsetSum(ll n,ll t)
{
    if(n==0)
    {
        if(t==0)
            return true;
        else   
            return false;
    }
    if(Dp[n][t] != false)
    {
        return Dp[n][t];
    }
    if(arr[n-1] <= t)
    {
        bool op1 = subsetSum(n-1,t-arr[n-1]);
        bool op2 = subsetSum(n-1,t);

        return Dp[n][t] = op1 || op2;
    }
    else
        return Dp[n][t] = subsetSum(n - 1, t);
}
int main()
{
    ll n,x;
    cin>>n>>x;
    ll s = 0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            Dp[i][j] = false;
        }
    }
    ll s1 = (s+x)/2;
    if(subsetSum(n,s1))
    {
        if (abs(s1-(s - s1)) == x)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}
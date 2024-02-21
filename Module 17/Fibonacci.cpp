#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 5;
ll DP[N];
ll fib(ll n)
{
    if (n == 0 || n == 1)
        return n;
    if(DP[n] != -1)
    {
        return DP[n];
    }
    ll ans = fib(n-1) + fib(n-2);
    DP[n] = ans;
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    memset(DP,-1,sizeof(DP));
    cout<<fib(n)<<endl;
    return 0;
}
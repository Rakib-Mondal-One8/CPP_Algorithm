#include <bits/stdc++.h>
#define ll long long int
using namespace std;
map<ll,bool>mp ;
bool canReach(ll n, ll x)
{
    if (x == n)
        return true;
    if (x > n)
        return false;
    if(mp.find(x) != mp.end())
        return mp[x];
    bool op1 = canReach(n, x * 10);
    bool op2 = canReach(n, x * 20);

    return mp[x] = op1 || op2;
}
int main()
{
    ll tCase;
    cin >> tCase;

    while (tCase--)
    {
        ll n;
        cin >> n;

        bool ans = canReach(n, 1);
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
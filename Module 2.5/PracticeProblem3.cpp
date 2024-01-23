#include<bits/stdc++.h>
using namespace std;
vector<int> v[1001];
int main()
{
    int n,e;
    cin>>n>>e;

    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int x;
    cin>>x;
    int nodes = 0;
    for(int val : v[x])
    {
        nodes++;
    }
    cout<<nodes<<endl;
    return 0;
}
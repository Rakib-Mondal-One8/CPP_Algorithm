#include<bits/stdc++.h>
using namespace std;
vector<int> v[100];
bool visit[100];

void dfs(int src)
{
    cout<<src<<endl;
    visit[src] = true;

    for(int child : v[src])
    {
        if(!visit[child])
        {
            dfs(child);
            visit[child] = true;
        }
    }
}

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
    memset(visit,false,sizeof(visit));

    for(int i=0;i<n;i++)
    {
        if(!visit[i])
        {
            dfs(i);
        }
    }
    return 0;
}
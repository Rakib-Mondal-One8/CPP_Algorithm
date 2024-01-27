/*
Question: You will be given an undirected graph as input. 
You need to tell the number of components in this graph.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> v[1001];
bool visit[1001];

void dfs(int src)
{
    visit[src] = true;
    for(int child : v[src])
    {
        if(!visit[child])
        {
            dfs(child);
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
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(!visit[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<endl;

    return 0;
}
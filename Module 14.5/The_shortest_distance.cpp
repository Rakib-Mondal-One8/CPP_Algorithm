#include<bits/stdc++.h>
using namespace std;
int adj[1001][1001];
bool vis[1001];
int dis[1001];
vector<int> v[1001];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;

    while(!q.empty())
    {
        int pr  = q.front();
        q.pop();

        for(int child : v[pr])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                dis[child] = dis[pr]+1;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;

    int x;
    cin>>x;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>adj[i][j];
            if(adj[i][j] == 1)
            {
                v[i].push_back(j);
            }
        }
    }
    memset(dis,-1,sizeof(dis));
    memset(vis,false,sizeof(vis));
    bfs(x);
    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
    return 0;
}
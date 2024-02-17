#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> V[N];
bool vis[N];
int dis[N];
int parent[N];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;

    while(!q.empty())
    {
        int p = q.front();
        q.pop();

        for(int child : V[p])
        {
            if(!vis[child])
            {
                q.push(child);
                dis[child] = dis[p]+1;
                vis[child] = true;
                parent[child] = p;
            }
        }
    }
}
void printPath(int d)
{
    if(parent[d] == -1)
    {
        cout<<d<<" ";
        return;
    }
    printPath(parent[d]);
    cout<<d<<" ";
}
int main()
{
    int v, e;
    cin >> v >> e;

    int s, d;
    cin >> s >> d;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        V[a].push_back(b); 
        V[b].push_back(a); 
    }
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    memset(parent,-1,sizeof(parent));
    bfs(s);
    cout<<dis[d]<<endl;
    printPath(d);
    return 0;
}
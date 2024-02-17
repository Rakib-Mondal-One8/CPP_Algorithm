#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];

bool vis[N];
int parent[N];
int cnt = 0;
void dfs(int src)
{
    vis[src] = true;
    for (int child : adj[src])
    {
        if (vis[child] && parent[src] != child)
        {
            cnt++;
        }
        if (!vis[child])
        {
            parent[child] = src;
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    dfs(1);
    cout<<cnt/2<<endl;
    return 0;
}
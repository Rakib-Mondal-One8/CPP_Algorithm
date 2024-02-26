#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool vis[100];
int cnt = 0;
void dfs(int src)
{
    cnt++;
    vis[src] = true;
    for (int child : adj[src])
    {
        if (!vis[child])
        {
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
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }
    int k;
    cin >> k;
    dfs(k);
    cout<< cnt-1 << endl;
    return 0;
}
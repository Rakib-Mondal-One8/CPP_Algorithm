#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visit[N];
int parent[N];
int ans = false;
void dfs(int src)
{
    visit[src] = true;
    for (int child : adj[src]) // Cycle Detection
    {
        if (visit[child] && parent[src] != child)
        {
            ans = true;
            return;
        }
        if (!visit[child])
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
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(parent,-1,sizeof(parent));
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            dfs(i);
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << parent[i] << endl;
    // }
    if (ans)
        cout << "Cycle Detected" << endl;
    else
        cout << "Cycle Not" << endl;
    return 0;
}
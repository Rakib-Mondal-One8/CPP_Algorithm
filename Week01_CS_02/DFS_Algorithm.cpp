#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool visit[1001];

int c = 0;
void dfs(int src)
{
    c++;
    cout << src << " ";
    visit[src] = true;

    for (int child : adj[src])
    {
        if (!visit[child])
        {
            dfs(child);
        }
    }
    // return count;
}

int main()
{
    int nde, edge;
    cin >> nde >> edge;

    while (edge--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= nde; i++)
    {
        if (!visit[i])
        {
            c = 0;
            dfs(i);
            if (c > 1)
                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
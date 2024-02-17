#include <bits/stdc++.h>
using namespace std;
int grid[1001][1001];
bool vis[1001];
bool path[1001];
vector<int> V[1001];
int cnt = 0;
void dfs(int src)
{
    vis[src] = true;
    path[src] = true;

    for (int child : V[src])
    {
        if (path[child] == true)
        {
            cnt++;
        }
        if (!vis[child])
        {
            dfs(child);
        }
    }
    path[src] = false;
}
int main()
{
    int n;
    cin >> n;
    // if (n == 1)
    // {
    //     cout << cnt << endl;
    //     return 0;
    // }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
                V[i].push_back(j);
        }
    }
    memset(vis, false, sizeof(vis));
    memset(path, false, sizeof(path));
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    cout << cnt << endl;
    return 0;
}
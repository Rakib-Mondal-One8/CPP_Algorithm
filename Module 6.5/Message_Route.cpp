#include <bits/stdc++.h>
using namespace std;
vector<int> V[100001];
int parent[100001];
bool vis[100001];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int pr = q.front();
        q.pop();

        for (int child : V[pr])
        {
            if (!vis[child])
            {
                vis[child] = true;
                parent[child] = pr;
                q.push(child);
            }
        }
    }
}
void printPath(int x)
{
    if (x == -1)
        return;

    printPath(parent[x]);
    cout << x << " ";
}
int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        V[a].push_back(b);
        V[b].push_back(a);
    }

    memset(parent, -1, sizeof(parent));
    bfs(1);
    int x = n;
    int cnt = 0;
    while (x != -1)
    {
        x = parent[x];
        cnt++;
    }
    if (cnt > 1)
    {
        cout << cnt << endl;
        printPath(n);
    }
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> v[1001];
int level[1001];
bool visit[1001];
int parent[1001];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    level[src] = 0;
    visit[src] = true;
    while (!q.empty())
    {
        int pr = q.front();
        q.pop();

        for (int child : v[pr])
        {
            if (!visit[child])
            {
                q.push(child);
                visit[child] = true;
                level[child] = level[pr] + 1;
                parent[child] = pr;
            }
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
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(level, -1, sizeof(level));
    memset(visit, false, sizeof(visit));
    memset(parent, -1, sizeof(parent));
    int src, des;
    cin >> src >> des;
    bfs(src);

    int x = des;
    vector<int> path;
    while (x != -1)
    {
        path.push_back(x);
        x = parent[x];
    }
    reverse(path.begin(), path.end());
    for (int val : path)
    {
        cout << val << endl;
    }
    return 0;
}
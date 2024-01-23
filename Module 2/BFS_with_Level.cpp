#include <bits/stdc++.h>
using namespace std;
vector<int> v[1001];
bool visit[1001];
int level[1001];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int pr = q.front();
        q.pop();

        // cout << pr << endl;
        for (int child : v[pr])
        {
            if (!visit[child])
            {
                q.push(child);
                visit[child] = true;
                level[child] = level[pr] + 1;
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
    memset(visit, false, sizeof(visit));
    memset(level, -1, sizeof(level));
    int src;
    cin >> src;
    bfs(src);
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << level[i] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> v[1001];
bool visit[1001];
void bfs(int src, int des)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    visit[src] = true;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int pr = p.first;
        int l = p.second;

        // cout << pr << endl;
        if (pr == des)
        {
            cout << l << endl;
        }
        for (int child : v[pr])
        {
            if (!visit[child])
            {
                q.push({child, l + 1});
                visit[child] = true;
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
    int src;
    cin >> src;
    bfs(src, 6);

    return 0;
}
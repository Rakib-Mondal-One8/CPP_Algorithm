#include <bits/stdc++.h>
using namespace std;
vector<int> v[1001];
bool visit[1001];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;

    while (!q.empty())
    {
        int pr = q.front();
        q.pop();

        cout << pr << endl;
        for (int child : v[pr])
        {
            if (!visit[child])
            {
                q.push(child);
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
    bfs(src);
    return 0;
}
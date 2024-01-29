#include <bits/stdc++.h>
using namespace std;
const int n = 1e5 + 5;
vector<int> adj[n];
bool visit[n];
int parent[n];
bool ans = false;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        int pr = q.front();
        q.pop();

        for (int child : adj[pr])
        {
            if (visit[child] && parent[pr] != child) // cycle detecting condition
            {
                ans = true;
            }
            if (!visit[child])
            {
                q.push(child);
                parent[child] = pr;
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

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
            bfs(i);
    }
    if (ans)
        cout << "Yes Cycle Present" << endl;
    else
        cout << "Cycle Not Found" << endl;
    return 0;
}
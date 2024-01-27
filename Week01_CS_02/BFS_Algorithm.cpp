#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visit[1001];
int bfs(int src)
{
    int count = 0;
    queue<int> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        int pr = q.front();
        q.pop();
        cout << pr << " ";
        count++;
        for (int child : adj[pr])
        {
            if (!visit[child])
            {
                q.push(child);
                visit[child] = true;
            }
        }
    }
    cout << endl;
    return count;
}
int main()
{
    int vtx, edge;
    cin >> vtx >> edge;

    while (edge--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visit, false, sizeof(visit)); // you can remove this line .
    // Because visit in decleared universally so its all value are false(0) defaultly.
    int count = 0;
    for (int i = 1; i <= vtx; i++)
    {
        if (!visit[i])
        {
            if (bfs(i) > 1) // if component has only one vertex then no need to consider that as a component.
                count++;
        }
    }
    cout << "Component " << count << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visit[1001];
bool path[1001];
bool ans = false;

void dfs(int src)
{
    visit[src] = true;
    path[src] = true;
    for (int child : adj[src])
    {
        if(path[child] == true) // path visit means ... also visited . Because path is visiting when visiting
        {
            ans = true;
        }
        if (!visit[child])
        {
            dfs(child);
        }
    }
    path[src] = false;
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
        // adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if(!visit[i])
        {
            dfs(i);
        }
    }
    if (ans)
        cout << "Cycle Detected" << endl;
    else
        cout << "Cycle Not Detected" << endl;
    return 0;
}
/*
Question 1: You will be given an undirected graph as input.
Then you will be given a query Q. For each query,
you will be given source S and destination D. You need to print the shortest distance between S and D.
If there is no path from S to D, print -1.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool visit[1005];
int parent[1005];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visit[s] = true;
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
    int Query;
    cin >> Query;
    while (Query--)
    {
        int s, des;
        cin >> s >> des;
        memset(visit, false, sizeof(visit));
        memset(parent, -1, sizeof(parent));
        bfs(s);
        if(!visit[des])
        {
            cout<<"-1"<<endl;
            continue;
        }
        int x = des;
        int path = 0;
        while(x != -1)
        {
            path++;
            x = parent[x];
        }
        cout<<path - 1<<endl;
    }
    return 0;
}

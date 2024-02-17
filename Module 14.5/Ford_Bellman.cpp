#include <bits/stdc++.h>
using namespace std;
int dis[1001];
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;

        edges.push_back(Edge(u, v, c));
    }
    for(int i=1;i<=n;i++)
    {
        dis[i] = 30000;
    }
    dis[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (Edge ed : edges)
        {
            if (dis[ed.u] < 30000 && dis[ed.u] + ed.c < dis[ed.v])
            {
                dis[ed.v] = dis[ed.u] + ed.c;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {

        cout << dis[i] << " ";
    }
    return 0;
}
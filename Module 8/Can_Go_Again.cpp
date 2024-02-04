#include <bits/stdc++.h>
#define ll long long int
#define lm LLONG_MAX
using namespace std;
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
long long int dis[1001];
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;

        EdgeList.push_back(Edge(u, v, c));
    }
    for (int i = 0; i <= n; i++)
    {
        dis[i] = lm;
    }
    int src;
    cin >> src;
    dis[src] = 0;
    for (int i = 1; i <= n-1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;

            if (dis[u] < lm && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    int cycle = false;
    for (Edge ed : EdgeList)
    {
        int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;

        if (dis[u] < lm && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }

    if (cycle == true)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        int TestCase;
        cin >> TestCase;

        while (TestCase--)
        {
            int d;
            cin >> d;

            if (d > 0 && d <= n && dis[d] < lm)
            {
                cout << dis[d] << endl;
            }
            else
            {
                cout << "Not Possible" << endl;
            }
        }
    }

    return 0;
}
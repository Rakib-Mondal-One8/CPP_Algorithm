#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 5;
long long int  parent[N];
long long int sz[N];
void make(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        sz[i] = 1;
    }
}
int dsu_find(int n)
{
    if (parent[n] == -1)
        return n;
    return parent[n] = dsu_find(parent[n]);
}
void Union(int n1, int n2)
{
    int l1 = dsu_find(n1);
    int l2 = dsu_find(n2);

    if (sz[l1] < sz[l2])
        swap(l1, l2);
    parent[l2] = l1;
    sz[l1] += sz[l2];
}
class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int main()
{
    int n, e;
    cin >> n >> e;

    make(n);
    vector<Edge> edges;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    sort(edges.begin(), edges.end(), cmp);
    int remove = 0;
    long long int totalCost = 0;
    for (Edge ed : edges)
    {
        if (dsu_find(ed.u) == dsu_find(ed.v))
        {
            remove++;
            continue;
        }
        Union(ed.u, ed.v);
        totalCost += ed.w;
    }
    int component = 0;
    for(int i=1;i<=n;i++)
    {
        if(parent[i] == -1) component++;
    }
    if (component > 1)
    {
        cout << "Not Possible" << endl;   
    }
    else
    {
        cout << remove << " " << totalCost << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int parent[1001];
int sz[1001];
void make(int v)
{
    parent[v] = v;
    sz[v] = 1;
}
int find(int nde)
{
    if (parent[nde] == nde)
        return nde;
    return parent[nde] = find(parent[nde]);
}
void Union(int nde1, int nde2)
{
    int a = find(nde1);
    int b = find(nde2);

    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
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

    vector<Edge> Elist;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Elist.push_back(Edge(u, v, w));
    }
    for (int i = 1; i < n; i++)
    {
        make(i);
    }
    sort(Elist.begin(), Elist.end(), cmp);
    int cost = 0;
    for (auto ed : Elist)
    {
        if (find(ed.u) != find(ed.v))
        {
            Union(ed.u, ed.v);
            cost += ed.w;
        }
    }
    cout << cost << endl;

    return 0;
}
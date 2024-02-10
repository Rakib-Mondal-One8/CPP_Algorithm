#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int group_size[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int find(int nde)
{
    if (parent[nde] == -1)
        return nde;
    return parent[nde] = find(parent[nde]); // path compresion
}
void dsu_union_by_size(int nde1, int nde2)
{
    int l1 = find(nde1);
    int l2 = find(nde2);

    if (group_size[l1] > group_size[l2])
    {
        parent[l2] = l1;
        group_size[l1] += group_size[l2];
    }
    else
    {
        parent[l1] = l2;
        group_size[l2] += group_size[l1];
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
    dsu_initialize(n);
    vector<Edge> edgeList;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edgeList.push_back(Edge(u, v, w));
    }
    sort(edgeList.begin(), edgeList.end(), cmp);
    int totalCost = 0;
    for (Edge ed : edgeList)
    {
        int leaderU = find(ed.u);
        int leaderV = find(ed.v);

        if (leaderU == leaderV)
        {
            continue;
        }
        else
        {
            dsu_union_by_size(ed.u, ed.v);
            totalCost += ed.w;
        }
    }
    cout << totalCost << endl;
    return 0;
}
/*
Problem Statement:
You live in a city where there are N buildings, and E roads connect those buildings.
Each road has a distance, and they are two-way roads.
You want to start a business in your city where you will provide ISP service.
For that reason, you need to connect all buildings with your central wire cable through the roads.
As the price of optical fiber is high, you want to reduce the cost as much as possible.
If you know the distance of the roads, can you calculate the minimum cost to connect all buildings with your cable?
The cost of optical fiber is equal to the distance of any road.
*/

#include <bits/stdc++.h>
using namespace std;
int parent[1001];
int sz[1001];
void make(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}
int find(int nde)
{
    if (parent[nde] == nde)
        return nde;
    return parent[nde] = find(parent[nde]); // path compressed
}
void Union(int nde1, int nde2)
{
    int l1 = find(nde1);
    int l2 = find(nde2);

    if (sz[l1] > sz[l2])
    {
        parent[l2] = l1;
        sz[l1] += sz[l2];
    }
    else
    {
        parent[l1] = l2;
        sz[l2] += sz[l1];
    
    }
    
}
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
bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}
int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;
    make(n);
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back(Edge(a, b, c));
    }
    sort(edges.begin(), edges.end(), cmp);
    int minCost = 0;
    for (Edge ed : edges)
    {
        int a = find(ed.u);
        int b = find(ed.v);

        if (a == b)
        {
            continue;
        }
        else
        {
            Union(a, b);
            minCost += ed.c;
        }
    }
    cout << minCost << endl;
    return 0;
}
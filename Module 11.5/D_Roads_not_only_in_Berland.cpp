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
    int u, v;
    Edge(int u, int v)
    {
        this->u = u;
        this->v = v;
    }
};

int main()
{
    int n;
    cin >> n;
    int e = n - 1;
    vector<Edge> V;
    while (e--)
    {
        int u, v;
        cin >> u >> v;

        V.push_back(Edge(u, v));
    }
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }

    vector<pair<int, int>> close, open;
    for (auto ed : V)
    {
        int a = find(ed.u);
        int b = find(ed.v);

        if (a != b)
        {
            Union(a, b);
        }
        else
            close.push_back({ed.u, ed.v});
    }
    int cnt = 0;
    vector<int> cmpnt;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == i)
        {
            cnt++;
            cmpnt.push_back(i);
        }
    }
    for (int i = 1; i < cmpnt.size(); i++)
    {
        open.push_back({cmpnt[i - 1], cmpnt[i]});
    }
    if (close.empty() && open.empty())
    {
        cout << "0" << endl;
    }
    else
    {
        cout << close.size() << endl;
        for (int i = 0; i < close.size(); i++)
        {
            cout << close[i].first << " " << close[i].second << " " << open[i].first << " " << open[i].second << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
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
int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> v[n];
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b, c});
    }

    vector<Edge> edge;
    for (int i = 0; i < n; i++)
    {
        for (auto child : v[i])
        {
            int childNde = child.first;
            int cost = child.second;
            edge.push_back(Edge(i,childNde,cost));
        }
    }
    for (Edge ed : edge)
    {
        cout << ed.u << " " << ed.v << " " << ed.c << endl;
    }
    return 0;
}
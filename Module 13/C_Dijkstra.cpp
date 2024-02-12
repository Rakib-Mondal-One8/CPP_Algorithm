#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
using namespace std;
const int N = 1e5 + 5;
vector<pi> a[N];
ll parent[N];
ll dis[N];
class cmp
{
public:
    bool operator()(pi a, pi b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int s)
{
    priority_queue<pi, vector<pi>, cmp> pq;
    pq.push({s, 0});
    dis[s] = 0;
    while (!pq.empty())
    {
        pi pr = pq.top();
        pq.pop();

        ll Nde = pr.first;
        ll cost = pr.second;

        for (pi child : a[Nde])
        {
            ll childNde = child.first;
            ll childCost = child.second;

            if (cost + childCost < dis[childNde])
            {
                dis[childNde] = cost + childCost;
                pq.push({childNde, dis[childNde]});
                parent[childNde] = Nde;
            }
        }
    }
}
void path(int des)
{
    if (parent[des] == -1)
    {
        cout << des << " ";
        return;
    }
    path(parent[des]);
    cout << des << " ";
}
int main()
{
    ll n, e;
    cin >> n >> e;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        a[u].push_back({v, c});
        a[v].push_back({u, c});
    }
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        dis[i] = 1e18;
    }
    dijkstra(1);

    if (dis[n] == 1e18)
    {
        cout << -1 << endl;
    }
    else
        path(n);
    return 0;
}
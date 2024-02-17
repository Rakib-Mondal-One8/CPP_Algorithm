#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
using namespace std;
vector<pi> V[10001];
ll parent[10001];
ll dis[10001];
class cmp
{
    public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void bfs(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty())
    {
        pi pr = pq.top();
        pq.pop();
        ll nde = pr.first;
        ll cost = pr.second;

        for (auto child : V[nde])
        {
            ll childNde = child.first;
            ll childCost = child.second;

            if (cost + childCost < dis[childNde])
            {
                pq.push({childNde, cost + childCost});
                dis[childNde] = cost + childCost;
                parent[childNde] = nde;
            }
        }
    }
}
void printPath(int d)
{
    if(parent[d] == -1)
    {
        cout<<d<<" ";
        return;
    }
    printPath(parent[d]);
    cout<<d<<" ";
}
int main()
{
    ll n, e;
    cin >> n >> e;

    ll s, d;
    cin >> s >> d;
    while (e--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        V[u].push_back({v, c});
        V[v].push_back({u, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
        parent[i] = -1;
    }
    bfs(s);
    if (dis[d] != 1e18)
    {
        cout << dis[d] << endl;
        printPath(d);
    }
    else
    {
        cout << "-1" << endl;
    }
    return 0;
}
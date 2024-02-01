#include <bits/stdc++.h>
#define ll long long int
using namespace std;
// const int N = 1e5 + 5;
int adj[1001][1001];
vector<pair<int, int>> v[1001];
int dis[1001];
class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({s, 0});
    dis[s] = 0;
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();

        int node = p.first;
        int cost = p.second;

        for (pair<int, int> child : v[node])
        {
            int childNode = child.first;
            int childCost = child.second;

            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode, cost + childCost});
            }
        }
    }
}
int main()
{
    int n, s, f;
    cin >> n >> s >> f;

    s--;
    f--;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] > 0)
            {
                v[i].push_back({j, adj[i][j]});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(s);
    if (dis[f] == INT_MAX)
        cout << "-1" << endl;
    else
        cout << dis[f] << endl;
    return 0;
}
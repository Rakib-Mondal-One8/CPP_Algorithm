// #include <bits/stdc++.h>
// #define ll long long int
// using namespace std;
// vector<pair<int, int>> V[1001];
// ll dis[10001];
// class cmp
// {
// public:
//     bool operator()(pair<int, int> a, pair<int, int> b)
//     {
//         return a.second > b.second;
//     }
// };
// void dijkstra(int src)
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
//     pq.push({src, 0});
//     dis[src] = 0;
//     while (!pq.empty())
//     {
//         pair<int, int> p = pq.top();
//         pq.pop();
//         int node = p.first;
//         int cost = p.second;

//         for (pair<int, int> child : V[node])
//         {
//             int childNode = child.first;
//             int childCost = child.second;

//             if (dis[node]<INT_MAX && cost + childCost < dis[childNode])
//             {
//                 dis[childNode] = cost + childCost;
//                 pq.push({childNode, cost + childCost});
//             }
//         }
//     }
// }
// int main()
// {
//     int n, e;
//     cin >> n >> e;

//     while (e--)
//     {
//         int u, v, c;
//         cin >> u >> v >> c;

//         V[u].push_back({v, c});
//     }
//     for (int i = 0; i <= n; i++)
//     {
//         dis[i] = INT_MAX;
//     }
//     int src;
//     cin >> src;
//     dijkstra(src);

//     int tCase;
//     cin >> tCase;

//     while (tCase--)
//     {
//         int D, Dc;
//         cin >> D >> Dc;
//         if (D > 0 && D <= n && dis[D] < INT_MAX && dis[D] <= Dc)
//         {
//             cout << "YES" << endl;
//         }
//         else
//             cout << "NO" << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int dis[1001];
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
    vector<Edge> Elist;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;

        Elist.push_back(Edge(u, v, c));
    }
    for (int i = 0; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    int src;
    cin >> src;
    dis[src] = 0;
    for (int i = 1; i < n; i++)
    {
        for (Edge e : Elist)
        {
            int u, v, c;
            u = e.u;
            v = e.v;
            c = e.c;

            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    int tCase;
    cin >> tCase;

    while (tCase--)
    {
        int D, Dc;
        cin >> D >> Dc;
        if (D > 0 && D <= n && dis[D] < INT_MAX && dis[D] <= Dc)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
        
    }
    return 0;
}
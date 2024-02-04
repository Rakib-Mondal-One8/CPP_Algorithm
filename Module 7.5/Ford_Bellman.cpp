#include<bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u,v,c;

    Edge(int u,int v,int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
int dis[10001];
int main()
{
    int n,e;
    cin>>n>>e;
    vector<Edge> V;
    while(e--)
    {
        int u,v,c;
        cin>>u>>v>>c;

        V.push_back(Edge(u-1,v-1,c));
    }
    for(int i=0;i<n;i++)
    {
        dis[i] = 30000;
    }

    //Bellman ford
    dis[0] = 0;
    for(int i=1;i<n;i++)
    {
        for(Edge ed : V)
        {
            int u,v,c;
            u = ed.u;
            v = ed.v;
            c = ed.c;

            if(dis[u] < 30000 && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c; // path relaxation
            }
        }
    }
    // answer
    for(int i=0;i<n;i++)
    {
        cout<<dis[i]<<" ";
    }

    return 0;
}

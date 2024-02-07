#include <bits/stdc++.h>
using namespace std;
int parent[101];
int GrpSz[101];
int level[101];
void initialize(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i] = -1;
        GrpSz[i] = 1;
        level[i] = 0;
    }
}
int find(int n)
{
    if(parent[n] == -1)
    return n;

    return parent[n] = find(parent[n]);
}
void dsu_union(int nde1 ,int nde2)
{
    int l1 = find(nde1);
    int l2 = find(nde2);

    parent[l1] = l2;
}
// Optimised Union technique
void dsu_by_size(int nde1,int nde2)
{
    int l1 = find(nde1);
    int l2 = find(nde2);

    if (GrpSz[l1] > GrpSz[l2])
    {
        parent[l2] = l1;
        GrpSz[l1] += GrpSz[l2];
    }
    else
    {
        parent[l1] = l2;
        GrpSz[l2] += GrpSz[l1];
    }
}
void dsu_by_rank(int nde1,int nde2)
{
    int l1 = find(nde1);
    int l2 = find(nde2);

    if(level[l1] > level[l2])
    {
        parent[l2] = l1;
    }
    else if(level[l2] > level[l1])
    {
        parent[l1] = l2;
    }
    else
    {
        parent[l2] = l1;
        level[l1]++;
    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    initialize(v);
    while(e--)
    {
        int x,y;
        cin>>x>>y;
        dsu_by_rank(x,y);  
    }
    //Updated parent
    for(int i=0;i<=v;i++)
    {
        cout<<parent[i]<<endl;
    }
    return 0;
}
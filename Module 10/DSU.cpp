#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int par[N];
int GrpSz[N];
int level[N];
void dsu_initialization(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        GrpSz[i] = 1;
        level[i] = 0;
    }
}
int dsu_find(int nde)
{
    if (par[nde] == -1)
        return nde;
    return par[nde] = dsu_find(par[nde]);
}
void dsu_union_by_size(int nde1, int nde2)
{
    int l1 = dsu_find(nde1);
    int l2 = dsu_find(nde2);

    if (GrpSz[l1] > GrpSz[l2])
    {
        par[l2] = l1;
        GrpSz[l1] += GrpSz[l2];
    }
    else
    {
        par[l1] = l2;
        GrpSz[l2] += GrpSz[l1];
    }
}
void dsu_union_by_rank(int nde1,int nde2)
{
    int l1 = dsu_find(nde1);
    int l2 = dsu_find(nde2);

    if(level[l1] > level[l2])
    {
        par[l2] = l1;
    }
    else if(level[l2]>level[l1])
    {
        par[l1] = l2;
    }
    else
    {
        par[l1] = l2;
        level[l2]++;
    }
}
int main()
{
    dsu_initialization(6);
    dsu_union_by_size(1, 2);
    dsu_union_by_size(2, 3);
    dsu_union_by_size(4, 5);
    dsu_union_by_size(5, 6);
    dsu_union_by_size(1, 4);

    cout << dsu_find(1) << endl;
    cout << dsu_find(4) << endl;

    return 0;
}
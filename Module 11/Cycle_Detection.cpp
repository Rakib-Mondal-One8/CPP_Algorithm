#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int group_size[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int find(int nde)
{
    if (parent[nde] == -1)
        return nde;
    return parent[nde] = find(parent[nde]); // path compresion
}
void dsu_union_by_size(int nde1, int nde2)
{
    int l1 = find(nde1);
    int l2 = find(nde2);

    if (group_size[l1] > group_size[l2])
    {
        parent[l2] = l1;
        group_size[l1] += group_size[l2];
    }
    else
    {
        parent[l1] = l2;
        group_size[l2] += group_size[l1];
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    dsu_initialize(n);
    bool cycle = false;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int la = find(a);
        int lb = find(b);

        if (la == lb)
            cycle = true;
        else
            dsu_union_by_size(a, b);
    }

    if (cycle)
        cout << "Cycle Found" << endl;
    else
        cout << "No Cycle" << endl;
    return 0;
}
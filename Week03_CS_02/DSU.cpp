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
    if (find(nde1) != find(nde2))
    {
        if (sz[nde1] < sz[nde2])
            swap(nde1, nde2);
        parent[nde2] = nde1;
        sz[nde1] += sz[nde2];
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i <= n; i++)
    {
        make(i);
    }
    while (e--)
    {
        int a, b;
        cin >> a >> b;

        Union(a, b);
    }

    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (parent[i] == i)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
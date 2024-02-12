#include <bits/stdc++.h>
using namespace std;

void convert(int n, vector<pair<int, int>> adj[])
{
    int mat[n + 1][n + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = -1;
            if (i == j)
                mat[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (pair<int, int> child : adj[i])
        {
            int childNode = child.first;
            int cost = child.second;
            mat[i][childNode] = cost;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> v[n + 1];
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b, c});
        // v[b].push_back({a, c});
    }
    convert(n, v);
    return 0;
}
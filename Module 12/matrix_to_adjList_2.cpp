#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int mat[n + 1][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    vector<pair<int, int>> v[n + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] > 0)
            {
                v[i].push_back({j, mat[i][j]});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (pair<int, int> child : v[i])
        {
            cout << "{" << child.first << ", " << child.second << "} ";
        }
        cout << endl;
    }
    return 0;
}
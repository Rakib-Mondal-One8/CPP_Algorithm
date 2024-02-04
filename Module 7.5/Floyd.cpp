#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long adj[101][101];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == -1)
            {
                adj[i][j] = INT_MAX;
            }
        }
    }
    // Floyd algorithm
    long long maxDis = INT_MIN;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && i != k && j != k && adj[i][k] < INT_MAX && adj[k][j] < INT_MAX && (adj[i][k] + adj[k][j]) < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] != INT_MAX && adj[i][j] > maxDis)
            {
                maxDis = adj[i][j];
            }
        }
    }
    if (maxDis == INT_MAX)
        maxDis = 0;
    cout << maxDis << endl;
    return 0;
}

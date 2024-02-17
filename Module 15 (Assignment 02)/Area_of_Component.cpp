#include <bits/stdc++.h>
using namespace std;
int const N = 1e4;
char grid[N][N];
bool vis[N][N];
int n, m;
vector<pair<int, int>> moves = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int cnt;
bool valid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '-' && !vis[i][j])
        return true;
    return false;
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + moves[i].first;
        int cj = sj + moves[i].second;

        if (valid(ci, cj))
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                cnt = 0;
                dfs(i, j);
                mn = min(mn, cnt);
            }
        }
    }
    if (cnt == 0)
        cout << "-1" << endl;
    else
        cout << mn << endl;
    return 0;
}
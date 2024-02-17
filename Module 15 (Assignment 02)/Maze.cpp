#include <bits/stdc++.h>
using namespace std;
char adj[1001][1001];
bool vis[1001][1001];
pair<int, int> path[1001][1001];
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
bool valid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m && adj[i][j] != '#' && !vis[i][j])
        return true;
    return false;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> pr = q.front();
        q.pop();
        int xi = pr.first;
        int xj = pr.second;
        if (adj[xi][xj] == 'D')
            return;
        for (int i = 0; i < 4; i++)
        {
            int ci = xi + moves[i].first;
            int cj = xj + moves[i].second;

            if (valid(ci, cj))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                path[ci][cj] = {moves[i].first, moves[i].second};
            }
        }
    }
}
int main()
{

    cin >> n >> m;
    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
            vis[i][j] = false;
            if (adj[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (adj[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }
    bfs(si, sj);
    if(vis[di][dj])
    {
        vector<pair<int, int>> v;
        while (di != si || dj != sj)
        {
            v.push_back({path[di][dj].first, path[di][dj].second});
            di -= v.back().first;
            dj -= v.back().second;
            if (adj[di][dj] != 'R')
                adj[di][dj] = 'X';
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << adj[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << adj[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
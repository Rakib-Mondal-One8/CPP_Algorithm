#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
char grid[1001][1001];
bool vis[1001][1001];
pair<int, int> path[1001][1001];
vector<pi> moves = {{0,1},{-1,0},{1,0},{0,-1}};
int n;
int si, sj;
int di, dj;
bool valid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < n && vis[i][j] == false && grid[i][j] != 'O')
        return true;
    return false;
}
void bfs(int si, int sj)
{
    queue<pi> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pi pr = q.front();
        q.pop();

        int ni = pr.first;
        int nj = pr.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = ni + moves[i].first;
            int cj = nj + moves[i].second;
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

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'X')
            {
                di = i;
                dj = j;
            }
            if (grid[i][j] == '@')
            {
                si = i;
                sj = j;
            }
        }
    }
    bfs(si, sj);
    if (!vis[di][dj])
    {
        cout << "N" << endl;
    }
    else
    {
        cout << "Y" << endl;
        vector<pair<int, int>> v;
        while (di != si || dj != sj)
        {
            if (grid[di][dj] != '@')
                grid[di][dj] = '+';
            v.push_back(path[di][dj]);
            di -= v.back().first;
            dj -= v.back().second;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
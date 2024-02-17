#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

int Forest[1001][1001];
bool vis[1001][1001];
int dis[1001][1001];
vector<pi> moves = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int n;
bool valid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < n && vis[i][j] == false && Forest[i][j] != -1)
        return true;
    return false;
}
void bfs(int si, int sj)
{
    queue<pi> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
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
                dis[ci][cj] = dis[ni][nj] + 1;
            }
        }
    }
}
int main()
{
    cin >> n;
    int si, sj;
    int ei, ej;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char s;
            cin >> s;
            if (s == 'T')
            {
                Forest[i][j] = -1;
                continue;
            }
            // if(s[j] == 'P') Forest[i][j] = 0;
            if (s == 'S')
            {
                si = i;
                sj = j;
            }
            else if (s == 'E')
            {
                ei = i;
                ej = j;
            }
            Forest[i][j] = 0;
        }
    }
    bfs(si, sj);
    cout << dis[ei][ej] << endl;

    return 0;
}
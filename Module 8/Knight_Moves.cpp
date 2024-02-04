#include <bits/stdc++.h>
using namespace std;
int Board[101][101];
bool visit[101][101];
int dis[101][101];
int n, m;
vector<pair<int, int>> p = {{-1, 2}, {1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || visit[i][j] == true)
    {
        return false;
    }
    return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visit[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> pr = q.front();
        q.pop();
        int pi = pr.first;
        int pj = pr.second;
        for (int i = 0; i < 8; i++)
        {
            int ci = pi + p[i].first;
            int cj = pj + p[i].second;

            if (valid(ci, cj))
            {
                visit[ci][cj] = true;
                dis[ci][cj] = dis[pi][pj] + 1;
                // Board[ci][cj] = 1;
                q.push({ci, cj});
            }
        }
    }
}
int main()
{
    int Q;
    cin >> Q;

    while (Q--)
    {
        cin >> n >> m;

        int ki, kj;
        cin >> ki >> kj;
        int qi, qj;
        cin >> qi >> qj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                Board[i][j] = 0;
            }
        }
        Board[qi][qj] = 1;
        memset(visit, false, sizeof(visit));
        bfs(ki, kj);
        if (visit[qi][qj])
        {
            cout << dis[qi][qj] << endl;
        }
        else
            cout << "-1" << endl;
    }
    return 0;
}
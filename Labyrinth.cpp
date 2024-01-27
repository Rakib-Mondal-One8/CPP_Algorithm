/*
########
#.A#...#
#.##.#B#
#......#
########
*/
#include <bits/stdc++.h>
using namespace std;

int maze[1001][1001]; // Update According to your Question
int n, m;
bool visit[1001][1001];

vector<pair<int, int>> adj = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int path[1001][1001];
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || maze[i][j] == -1)
    {
        return false;
    }
    return true;
}

/*
void dfs(pair<int, int> src)
{
    int a = src.first;
    int b = src.second;
    visit[a][b] = true;
    path[a][b] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ci = a + adj[i].first;
        int cj = b + adj[i].second;

        if (valid(ci, cj) && !visit[ci][cj])
        {
            dfs({ci, cj});
        }
    }
}
*/
void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);

    visit[src.first][src.second] = true;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int a = cur.first;
        int b = cur.second;
        path[a][b] = 1;
        for (int i = 0; i < 4; i++)
        {
            int ci = a + adj[i].first;
            int cj = b + adj[i].second;

            if (valid(ci, cj) && !visit[ci][cj])
            {
                q.push({ci, cj});
                visit[ci][cj] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m;

    pair<int, int> src, des;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
                maze[i][j] = -1;
            if (s[j] == 'A')
                src = {i, j};
            if (s[j] == 'B')
                des = {i, j};
        }
    }
    // dfs(src);
    bfs(src);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << path[i][j];
        }
        cout << endl;
    }
    if (visit[des.first][des.second])
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int grid[20][20];
bool visit[20][20];
int dis[20][20];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    return true;
}
// similar To Binary Tree Level Order Traversal
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visit[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int a = p.first;
        int b = p.second;
        q.pop();

        cout << grid[a][b] << endl;
        
        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;

            if (valid(ci, cj) == true && visit[ci][cj] == false)
            {
                q.push({ci, cj});
                visit[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
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
    memset(visit, false, sizeof(visit));
    memset(dis,-1,sizeof(dis));

    int si, sj;
    cin >> si >> sj;

    bfs(si, sj);
    cout<<dis[1][1]<<endl;

    return 0;
}
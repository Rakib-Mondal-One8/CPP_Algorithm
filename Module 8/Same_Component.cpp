#include <bits/stdc++.h>
using namespace std;
int grid[1001][1001];
bool visit[1001][1001];
vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || visit[i][j] == true || grid[i][j] == -1)
    {
        return false;
    }
    return true;
}
void dfs(int si, int sj)
{
    visit[si][sj] = true;
    for (int i=0;i<4;i++)
    {
        int ci = si + p[i].first;
        int cj = sj + p[i].second;

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
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '.')
            {
                grid[i][j] = 0;
            }
            if (s[j] == '-')
            {
                grid[i][j] = -1;
            }
        }
    }
    memset(visit,false,sizeof(visit));
    
    int si, sj;
    cin >> si >> sj;
    int di, dj;
    cin >> di >> dj;
    dfs(si, sj);

    if (visit[si][sj] == true && visit[di][dj] == true)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}
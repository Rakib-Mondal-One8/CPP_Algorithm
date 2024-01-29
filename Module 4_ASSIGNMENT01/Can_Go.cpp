#include <bits/stdc++.h>
using namespace std;
int building[1001][1001];
int n, m;
bool visit[1001][1001];
vector<pair<int, int>> adj = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || building[i][j] == -1)
    {
        return false;
    }
    return true;
}
void dfs(pair<int, int> src)
{
    int a = src.first;
    int b = src.second;
    visit[a][b] = true;
    for (int i = 0; i < 4; i++)
    {
        int x = a + adj[i].first;
        int y = b + adj[i].second;
        if (valid(x, y) && !visit[x][y])
        {
            dfs({x, y});
        }
    }
}

int main()
{

    cin >> n >> m;

    pair<int, int> des, src;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'A')
                src = {i, j};
            if (s[j] == 'B')
                des = {i, j};

            if (s[j] == '#')
                building[i][j] = -1;
        }
    }
    dfs({src.first, src.second});
    if (visit[des.first][des.second] == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int maze[1001][1001];
int n, m;
bool visit[1001][1001];
vector<pair<int,int>> c = {{0,1},{0,-1},{-1,0},{1,0}};
void dfs(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m || maze[i][j] == -1 || visit[i][j])
    {
        return ;
    }
    visit[i][j] = true;
    for(int k=0;k<4;k++)
    {
        int x = i + c[k].first;
        int y = j + c[k].second;

        dfs(x,y);
    }
}

int apartments()
{
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maze[i][j] == 0 && !visit[i][j])
            {
                cnt++;
                dfs(i,j);
            }
        }
    }
    return cnt;
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
            if (s[j] == '#')
                maze[i][j] = -1;
        }
    }
    int ans = apartments();
    cout<<ans<<endl;
    return 0;
}

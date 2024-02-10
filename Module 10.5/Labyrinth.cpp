#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int grid[N][N];
bool vis[N][N];
int n, m;
int cnt = 0;
vector<pair<int,int>> moves = {{0,-1},{0,1},{-1,0},{1,0}};
bool valid(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m || vis[i][j] == true || grid[i][j] == -1) return false;
    return true;
}
vector<char> path;
void bfs(int fi,int fj)
{
    queue<pair<int,int>> q;
    q.push({fi,fj});
    vis[fi][fj] = true;

    while(!q.empty())
    {
        pair<int,int> pr = q.front();
        q.pop();
        int si = pr.first;
        int sj = pr.second;
        if(grid[si][sj] == 2) return;
        for(int i=0;i<4;i++)
        {
            int ci = si + moves[i].first;
            int cj = sj + moves[i].second;
            if(valid(ci,cj))
            {
                if(i == 0) path.push_back('L');
                else if(i==1) path.push_back('R');
                else if(i==2) path.push_back('U');
                else path.push_back('D');
                q.push({ci,cj});
                vis[ci][cj] = true;
                cnt++;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int x, y;
    int dx,dy;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'A')
            {
                grid[i][j] = 1;
                x = i;
                y = j;
            }
            if (s[j] == 'B')
            {
                grid[i][j] = 2;
                dx = i;
                dy = j;
            }
            if (s[j] == '#')
            {
                grid[i][j] = -1;
            }
            if (s[j] == '.')
                grid[i][j] = 0;
        }
    }
    bfs(x,y);
    if(vis[dx][dy] == true)
    {
        cout<<"YES"<<endl;
        cout<<cnt<<endl;
        for(char p : path)
        {
            cout<<p;
        }

    }

    return 0;
}
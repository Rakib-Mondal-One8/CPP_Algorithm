#include <bits/stdc++.h>
using namespace std;

int maze[1001][1001];
int n, m;
bool visit[1001][1001];
vector<pair<int, int>> c = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int room = 0;
vector<int> result;

void dfs(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || maze[i][j] == -1 || visit[i][j])
    {
        return;
    }
    room++;
    visit[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int x = i + c[k].first;
        int y = j + c[k].second;

        dfs(x, y);
    }
    
}

void apartments()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            room = 0;
            if (maze[i][j] == 0 && !visit[i][j])
            {
                dfs(i, j);
                result.push_back(room);
            }
        }
    }
    
}

int main()
{

    cin >> n >> m;
    bool Onlywalls = true;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
                maze[i][j] = -1;
            else Onlywalls = false;
        }
    }
    if(Onlywalls)
    {
        cout<<"0"<<endl;
        return 0;
    }
    apartments();
    sort(result.begin(),result.end());
    for(int val : result)
    {
        cout<<val<<" ";
    }
    return 0;
}

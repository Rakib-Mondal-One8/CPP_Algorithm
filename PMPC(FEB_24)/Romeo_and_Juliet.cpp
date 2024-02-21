/*
Problem Statement

Romeo and Juliet are a newly married couple. They went to Switzerland for their honeymoon. They had a plan in mind: they would test their fortune by staying in different cities and seeing if they could reunite in at most  steps. Switzerland has  cities numbered from  to , with  two-way roads connecting them.

Romeo is in city X, and Juliet is in city Y. In each step, they can cross one road and move from one city to another. It is not mandatory for both of them to cross; one can choose to stay in the same city if desired. However, the step will still be counted.

Can you tell if they can be reunited or not?

Input Format

First line will contain  N and E; The number of city and number of roads respectively.
Next  lines will contain A and B which means there is a road between A city B and .
Last line will contain X, Y and K.

Output Format

Output "YES" if they can be reunited otherwise output "NO".
Sample Input 0

8 9
0 1
4 0
4 2
2 3
1 3
2 5
5 6
6 7
6 3
4 7 2
Sample Output 0

YES
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visit[N];
int dis[N];
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visit[x] = true;
    dis[x] = 0; // parent of root is -1 [root is x
    while (!q.empty())
    {
        int nde = q.front();
        q.pop();

        for (int child : adj[nde])
        {
            if (!visit[child])
            {
                visit[child] = true;
                dis[child] = dis[nde]+1;
                q.push(child);
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int v, u;
        cin >> v >> u;

        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    memset(visit, false, sizeof(visit));
    memset(dis,-1,sizeof(dis));
    int x, y, k;
    cin >> x >> y >> k;

    bfs(x);

    if (dis[y] != -1 && dis[y]<= k*2)
    {   cout << "YES" << endl;
        // cout<<dis[y];
    }
    else
    {
        cout << "NO" << endl;
        // cout<<dis[y];
    }
    return 0;
}
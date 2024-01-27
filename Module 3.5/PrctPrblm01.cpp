/*
Question: You will be given an undirected graph as input. Then you will be given a node N.
You need to tell the number of nodes that can be visited from node N.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> v[1001];
bool visit[1001];
int cnt = 0;
void dfs(int src)
{
    cnt++;
    visit[src] = true;
    for (int child : v[src])
    {
        if (!visit[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }
    int vtx;
    cin >> vtx;
    dfs(vtx);
    cout<<cnt<<endl;
    return 0;
}
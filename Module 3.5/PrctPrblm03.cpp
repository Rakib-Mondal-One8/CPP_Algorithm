/*
Question: You will be given an undirected graph as input. 
You need to tell the number of nodes in each component in ascending order.
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> v[1001];
bool visit[1001];
int cnt = 0;
int dfs(int src)
{
    cnt++;
    visit[src] = true;

    for(int child : v[src])
    {
        if(!visit[child])
        {
            dfs(child);
        }
    }
    return cnt;
}

int main()
{
    int n,e;
    cin>>n>>e;

    while(e--)
    {
        int a,b;
        cin>>a>>b;

        v[a].push_back(b);
        v[b].push_back(a);
    }
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<n;i++)
    {
        if(!visit[i])
        {
            cnt = 0;
           q.push(dfs(i));
        }
    }
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    return 0;
}
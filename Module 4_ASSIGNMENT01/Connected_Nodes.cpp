#include <bits/stdc++.h>
using namespace std;
vector<int> v[1001];
bool visited[1001];

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
        visited[a] = true;
        visited[b] = true;
    }
    int Query;
    cin >> Query;

    while (Query--)
    {
        int src;
        cin >> src;
        if(visited[src] == false)
        {
            cout<<"-1"<<endl;
            continue;
        }
        priority_queue<int> pq;
        for(int child : v[src])
        {
            pq.push(child);
        }
        while(!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout<<endl;
       
    }
    return 0;
}
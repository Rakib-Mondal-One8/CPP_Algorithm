/*
You will be given an undirected graph which will be connected as input.
Then you will be given a level L.
You need to print the node values at level L in descending order.
The source will be 0 always.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> v[1001];
bool visit[1001];
vector<int> result;
void bfs(int src, int level)
{
    queue<pair<int, int>> q;
    q.push({src, 0});

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int pr = p.first;
        int l = p.second;
        if (l == level && pr != 0)
        {
            result.push_back(pr);
        }
        for (int child : v[pr])
        {
            if (!visit[child])
            {
                q.push({child, l + 1});
                visit[child] = true;
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
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    int l;
    cin >> l;
    memset(visit, false, sizeof(visit));
    bfs(0, l);
    sort(result.begin(), result.end(), greater<int>());
    for (int val : result)
    {
        cout << val<<" ";
    }
    cout<<endl;
    return 0;
}
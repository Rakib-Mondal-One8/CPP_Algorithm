#include <bits/stdc++.h>
using namespace std;
vector<int> v[1001];

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        // v[b].push_back(a);
    }
    int Query;
    cin >> Query;

    while (Query--)
    {
        int src, des;
        cin >> src >> des;
        
        int flag = 0;
        if (src == des)
        {
            flag = 1;
            
        }
        for(int child : v[src])
        {
            if(child == des)
            {
                flag = 1;
                break;
            }
            
        }
        if(flag == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
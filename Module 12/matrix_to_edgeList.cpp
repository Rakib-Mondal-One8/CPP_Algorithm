#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<pair<int,int>> edge;
    int mat[n+1][n+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j] == 1 && i!=j)
            {
                edge.push_back({i,j});
            }
        }
    }

    for(auto ed : edge)
    {
        cout<<ed.first<<" "<<ed.second<<endl;
    }
    return 0;
}
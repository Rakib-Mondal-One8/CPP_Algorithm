#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Q;
    cin >> Q;
    vector<int> v ;
    while (Q--)
    {
        int c, x;
        cin >> c;

        if (c == 1)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        else if (c == 2)
        {
            int minEven = INT_MAX;
            int idx = 0;
            for (int i=0;i<v.size();i++)
            {
                if (v[i] % 2 == 0 && v[i] < minEven)
                {
                    minEven = v[i];
                    idx = i;
                }
            }
            if (minEven != INT_MAX)
            {
                cout << minEven << endl;
                v.erase(v.begin() + idx);
            }    
            else
                cout << "empty" << endl;
        }
        else
        {
            int minOdd = INT_MAX;
            int idx = 0;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] % 2 != 0 && v[i] < minOdd)
                {
                    minOdd = v[i];
                    idx = i;
                }
            }
            if (minOdd != INT_MAX)
            {
                cout << minOdd << endl;
                v.erase(v.begin() + idx);
            }   
            else
                cout << "empty" << endl;
        }
    }
    return 0;
}
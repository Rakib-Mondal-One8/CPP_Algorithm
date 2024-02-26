#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int mx1 = INT_MIN;
        int idx1 = -1;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            arr.push_back(val);
            if (val > mx1)
            {
                mx1 = val;
                idx1 = i;
            }
        }
        int mx2 = INT_MIN;
        int idx2 = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != mx1 && arr[i] > mx2)
            {
                mx2 = arr[i];
                idx2 = i;
            }
        }
        if (idx1 < idx2)
        {
            cout << idx1 << " " << idx2 << endl;
        }
        else
        {
            cout << idx2 << " " << idx1 << endl;
        }
    }
    return 0;
}
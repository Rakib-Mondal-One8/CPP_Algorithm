#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        if (n > 2)
        {
            vector<long long int> arr(n + 5);
            vector<long long int> pref1(n + 5);
            vector<long long int> pref2(n + 5);
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }

            pref1[0] = arr[0];
            pref2[n - 1] = arr[n - 1];
            for (int i = 1; i < n; i++) // pref1
            {
                pref1[i] = pref1[i - 1] + arr[i];
            }
            for (int i = n - 2; i >= 0; i--) // pref2
            {
                pref2[i] = pref2[i + 1] + arr[i];
            }
            int cnt = 0;
            for (int i = 1; i < n - 1; i++)
            {
                if ( pref1[i] == pref2[i])
                {
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
        else
            cout << "0" << endl;
    }
    return 0;
}
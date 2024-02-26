#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tcase;
    cin >> tcase;

    while (tcase--)
    {
        long long int n;
        cin >> n;
        vector<bool> dp(n+1,false);
        dp[1] = true;
        for (int i = 1; i <= n; i++)
        {
           if(dp[i])
           {
               if (i + 3 <= n)
                   dp[i + 3] = true;
               if (i * 2 <= n)
                   dp[i * 2] = true;
           }
        }
        if (dp[n])
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

// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     int tcase;
//     cin >> tcase;

//     while (tcase--)
//     {
//         long long int n;
//         cin >> n;

//         vector<bool> dp(n + 1, false);
//         dp[1] = true; // Base case

//         // Bottom-up DP
//         for (long long int i = 1; i <= n; ++i)
//         {
//             if (dp[i])
//             {
//                 if (i + 3 <= n)
//                     dp[i + 3] = true;
//                 if (i * 2 <= n)
//                     dp[i * 2] = true;
//             }
//         }

//         if (dp[n])
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }
//     return 0;
// }

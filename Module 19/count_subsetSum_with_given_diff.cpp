#include <bits/stdc++.h>
using namespace std;
int arr[1005];
bool subset_sum(int arr[], int n, int s)
{
    if(n==0)
    {
        if(s==0)
        {
            return true;
        }
        else
            return false;
    }
    if(arr[n-1] <= s)
    {
        bool op1 = subset_sum(arr,n-1,s-arr[n-1]);
        bool op2 = subset_sum(arr,n-1,s);
        return op1 || op2;
    }
    else
        return subset_sum(arr, n - 1, s);
}
int main()
{
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s += arr[i];
    }

    int Diff;
    cin >> Diff;
    int want = (Diff + s) / 2; // according to (different + sum / 2 ) equation
    if (subset_sum(arr, n, want))
    {
        if (abs(want - (s - want)) == Diff)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
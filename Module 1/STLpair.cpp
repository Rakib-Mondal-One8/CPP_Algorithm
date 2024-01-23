#include <bits/stdc++.h>
using namespace std;
/*
class Pair
{
public:
    int first, second;
Pair(int a,int b)
    {
        first = a;
        second = b;
    }
};
*/
int main()
{
    // Pair p(10,20);
    pair<int,int> p; //STL
    p = {10,20};
    cout << p.first << " " << p.second << endl;
    return 0;
}
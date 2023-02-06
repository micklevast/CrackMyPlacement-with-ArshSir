#include <iostream>
#include <vector>
#include <cmath>
#define ll long long int
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        // int gotted = 0;
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         ll x = pow(i, j) * j;
        //         ll y = pow(j, i) * i;
        //         if (x < n && y < n)
        //         {
        //             if (x + y == n)
        //             {
        //                 gotted++;
        //                 cout << i << " " << j << endl;
        //                 break;
        //             }
        //         }
        //     }
        //     if (gotted)
        //         break;
        // }
        // if (gotted == 0)
        //     cout << -1 << endl;
        if (n & 1)
            cout << -1 << endl;
        else
            cout << 1 << " " << n / 2 << endl;
    }
}
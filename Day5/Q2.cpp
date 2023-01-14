#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#define ll long long int
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int diff = abs(a - b);
        if (c <= diff * 2 && (a <= (diff * 2) && b <= (diff * 2) && c <= (diff * 2)))
        {
            if (c > diff)
            {
                cout << c - diff << endl;
            }
            else
            {
                cout << c + diff << endl;
            }
        }
        else
            cout << -1 << endl;
    }
}
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int i = 0, j = 0;
        int ans = 0;
        for (int k = 0; k < n; k++)
        {
            if (str[k] == 'L')
            {
                i = i - 1;
            }
            else if (str[k] == 'R')
            {
                i = i + 1;
            }
            else if (str[k] == 'U')
            {
                j += 1;
            }
            else if (str[k] == 'D')
            {
                j -= 1;
            }
            if (i == 1 && j == 1)
            {
                ans++;
                break;
            }
        }
        if (ans > 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
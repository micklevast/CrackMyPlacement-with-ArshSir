#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
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
        int n;
        cin >> n;
        string str;
        cin >> str;
        int flag = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (str[i] == 'R' && str[i + 1] == 'L')
            {
                cout << 0 << endl;
                flag++;
                break;
            }
            if (str[i] == 'L' && str[i + 1] == 'R')
            {
                cout << i + 1 << endl;
                flag++;
                break;
            }
        }
        if (flag == 0)
            cout << -1 << endl;
    }
}
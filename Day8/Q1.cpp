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
// meth1-->fails at some case
int min(int a, int b)
{
    return a > b ? b : a;
}
int minFlipsMonoIncr(string s)
{
    int i = 0;
    int n = s.length() - 1;
    int len = n;
    int ii = i;
    int l0 = 0;
    int cc0 = 0;
    int ans = 0;
    while (ii < len && s[ii] == '1')
    {
        l0++;
        // cout<<" count l0:"<<l0<<endl;
        ii++;
        if (s[ii] == '0')
        {
            // cout<<"at:"<<ii<<" 0 founded\n";
            while (ii < len && s[ii] == '0')
            {
                cc0++;
                ii++;
            }
            break;
        }
    }
    // cout<<"l0:"<<l0<<"  cc0:"<<cc0<<endl;
    if (l0 < cc0)
    {
        ans += l0;
        i = cc0;
    }
    while (i <= n && s[i] == '0')
    {
        i++;
    }
    while (n >= 0 && s[n] == '1')
    {
        n--;
    }
    int c0 = 0, c1 = 0;
    for (int j = i; j <= n; j++)
    {
        if (s[j] == '0')
        {
            c0++;
        }
        else
        {
            c1++;
        }
    }
    return min(ans + c0, ans + c1);
}

// -----meth2
int minFlipsMonoIncr2(string s)
{
    int i = 0;
    int n = s.length();
    int c0 = count(s.begin(), s.end(), '0');
    int c1 = n - c0;
    int ans = min(c0, c1);
    int curr1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            curr1++;
        int tempAns = curr1 + (n - i - 1) - (c1 - curr1);
        ans = min(ans, tempAns);
    }
    return ans;
}

int main()
{
}
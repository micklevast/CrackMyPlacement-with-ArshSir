#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <math.h>
#include <algorithm>
#include <map>
#define ll long long int
using namespace std;
int max(int a, int b)
{
    return a > b ? a : b;
}
int maxProfit(vector<int> &p)
{
    int n = p.size();
    vector<int> later(n);
    later[n - 1] = p[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        later[i] = max(later[i + 1], p[i]);
    }
    // for (auto val : later)
    //     cout << val << " ";
    // cout << endl;
    int ans = INT_MIN;
    int i = 0;
    for (auto val : p)
    {
        ans = max(abs(later[i++] - val), ans);
        // cout << "ans:" << ans << endl;
    }
    return ans;
}
int main()
{
    vector<int> arr{7, 1, 5, 3, 6, 4};
    int ans = maxProfit(arr);
    cout << ans << endl;
}
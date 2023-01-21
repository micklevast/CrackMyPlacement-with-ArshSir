#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#define ll long long int
using namespace std;
class Solution
{
public:
    // int ans=0;
    int max(vector<int> arr)
    {
        int ans = INT_MIN;
        for (auto val : arr)
        {
            if (val > ans)
                ans = val;
        }
        return ans;
    }
    int min(vector<int> arr)
    {
        int ans = INT_MAX;
        for (auto val : arr)
        {
            if (val < ans)
                ans = val;
        }
        return ans;
    }
    pair<int, int> memo[41][41];
    pair<int, int> calValues(vector<int> &arr, int l, int r)
    {
        if (memo[l][r].first != -1)
            return memo[l][r];
        else if (l == r)
        {
            return {arr[l], 0};
        }
        int maxLeaf = INT_MIN;
        int nonLeafSum = INT_MAX;

        pair<int, int> lans, rans;
        for (int i = l; i < r; i++)
        {

            lans = calValues(arr, l, i);
            rans = calValues(arr, i + 1, r);
            maxLeaf = max({maxLeaf, lans.first, rans.first});
            nonLeafSum = min({nonLeafSum, lans.first * rans.first + lans.second + rans.second});
        }
        return memo[l][r] = {maxLeaf, nonLeafSum};
    }
    int mctFromLeafValues(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < 41; i++)
            for (int j = 0; j < n; j++)
                memo[i][j] = {-1, -1};

        return calValues(arr, 0, n - 1).second;
    }
};
int main()
{
    Solution s;
    vector<int> arr{1, 6, 5, 3};
    s.mctFromLeafValues(arr);
}
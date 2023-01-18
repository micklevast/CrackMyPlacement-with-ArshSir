#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#define ll long long int
using namespace std;

class Solution
{
public:
#define MOD 1000000007

    int reverse(int n)
    {
        int rev = 0;
        while (n > 0)
        {
            int r = n % 10;
            n /= 10;
            rev = rev * 10 + r;
        }
        return rev;
    }

    vector<int> reverse_of_nums(vector<int> arr)
    {
        vector<int> ans;
        for (auto val : arr)
        {
            ans.push_back(reverse(val));
        }
        return ans;
    }
    ll countNicePairs(vector<int> &nums)
    {
        vector<int> rev = reverse_of_nums(nums);
        map<int, int> mp;
        int i = 0;
        int ans = 0;
        for (auto val : nums)
        {
            if (mp.find(val - rev[i]) != mp.end())
            {
                int temp = (mp[val - rev[i]]);
                // cout << "temp:" << temp << endl;
                ans = (ans + temp) % MOD;
                // cnt+=(m[nums[i]-v[i]])%M;
            }

            mp[val - rev[i]]++;
            i++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> arr{35, 13, 62, 48, 10, 20, 40, 30};
    cout << s.countNicePairs(arr) << endl;
}
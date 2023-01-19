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
// meth1-------
int subarraysDivByK(vector<int> &nums, int k)
{
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum % k == 0)
            {
                ans++;
            }
        }
    }
    return ans;
}
// meth2------
int subarraysDivByK2(vector<int> &nums, int k)
{
    int ans = 0;
    map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    for (auto val : nums)
    {
        sum += val;
        int rem = sum % k;
        if (rem < 0)
            rem += k; //-->good but have to further understand
        cout << "rem:" << rem << endl;
        if (mp.find(rem) != mp.end())
        {
            ans += mp[rem];
            //    cout<<"ans:"<<ans<<endl;
        }
        mp[rem]++;
    }
    return ans;
}
int main()
{
}
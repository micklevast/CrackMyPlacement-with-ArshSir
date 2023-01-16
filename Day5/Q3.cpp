#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <map>
#define ll long long int
using namespace std;
vector<vector<ll>> fourSum1(vector<ll> &nums, ll target)
{
    set<vector<ll>> ans;
    ll n = nums.size();
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            for (ll k = j + 1; k < n; k++)
            {
                for (ll l = k + 1; l < n; l++)
                {
                    if (j != i && k != j && l != k)
                    {
                        ll sum = nums[i];
                        sum += nums[j];
                        sum += nums[k];
                        sum += nums[l];
                        if (sum == target)
                        {
                            vector<ll> temp{nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            ans.insert(temp);
                        }
                    }
                }
            }
        }
    }
    vector<vector<ll>> vec_ans;
    for (auto val : ans)
    {
        vec_ans.push_back(val);
    }
    return vec_ans;
}

vector<vector<ll>> fourSum2(vector<ll> &nums, ll target)
{
    set<vector<ll>> ans;
    ll n = nums.size();
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        mp[nums[i]] = i;
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            for (ll k = j + 1; k < n; k++)
            {
                ll sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                ll r = target - sum;
                if (mp.find(r) != mp.end())
                {
                    auto ptr = mp.find(r);
                    cout << "founded val:" << ptr->first << endl;
                    if (ptr->second != i && ptr->second != j && ptr->second != k)
                    {
                        vector<ll> temp{nums[i], nums[j], nums[k], nums[ptr->second]};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<ll>> vec_ans;
    for (auto val : ans)
    {
        vec_ans.push_back(val);
    }
    return vec_ans;
}

// ----------------meth3
vector<vector<ll>> fourSum3(vector<ll> &nums, ll target)
{
    unordered_set<ll> seen;
    set<multiset<ll>> ans_set;
    ll n = nums.size();
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            for (ll k = j + 1; k < n; k++)
            {
                ll lastNumber = target - (nums[i] + nums[j] + nums[k]);
                if (seen.count(lastNumber))
                    ans_set.emplace(multiset<ll>{nums[i], nums[j], nums[k], lastNumber});
            }
        }
        seen.insert(nums[i]);
    }
    vector<vector<ll>> ans(ans_set.size());
    for_each(begin(ans_set), end(ans_set), [&, i(0)](auto &el) mutable
             { ans[i++] = vector<ll>(begin(el), end(el)); });
    return ans;
}
// --------------meth4---->two poller
vector<vector<ll>> fourSum4(vector<ll> &nums, ll target)
{
    sort(nums.begin(), nums.end());
    ll n = nums.size();
    vector<vector<ll>> ans;
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = i + 1; j < n; ++j)
        {
            ll l = j + 1, r = n - 1;
            ll remain = target - nums[i] - nums[j];
            while (l < r)
            {
                if (nums[l] + nums[r] == remain)
                {
                    ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                    ++l;
                    --r;
                    while (l < r && nums[l - 1] == nums[l])
                        ++l; // Skip duplicate nums[l]
                }
                else if (nums[l] + nums[r] > remain)
                {
                    --r;
                }
                else
                {
                    ++l;
                }
            }
            while (j + 1 < n && nums[j] == nums[j + 1])
                ++j; // Skip duplicate nums[j]
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
            ++i; // Skip duplicate nums[i]
    }
    return ans;
}

int main()
{
    vector<ll> arr{1, 0, -1, 0, -2, 2};
    ll tar = 0;
    vector<vector<ll>> ans = fourSum1(arr, tar);
    for (auto val : ans)
    {
        for (auto v : val)
            cout << v << " ";

        cout << endl;
    }
}
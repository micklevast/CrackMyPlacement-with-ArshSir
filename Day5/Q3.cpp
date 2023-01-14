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
vector<vector<int>> fourSum1(vector<int> &nums, int target)
{
    set<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (j != i && k != j && l != k)
                    {
                        long long int sum = nums[i];
                        sum += nums[j];
                        sum += nums[k];
                        sum += nums[l];
                        if (sum == target)
                        {
                            vector<int> temp{nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            ans.insert(temp);
                        }
                    }
                }
            }
        }
    }
    vector<vector<int>> vec_ans;
    for (auto val : ans)
    {
        vec_ans.push_back(val);
    }
    return vec_ans;
}

vector<vector<int>> fourSum2(vector<int> &nums, int target)
{
    set<vector<int>> ans;
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                long long int sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                long long int r = target - sum;
                if (mp.find(r) != mp.end())
                {
                    auto ptr = mp.find(r);
                    cout << "founded val:" << ptr->first << endl;
                    if (ptr->second != i && ptr->second != j && ptr->second != k)
                    {
                        vector<int> temp{nums[i], nums[j], nums[k], nums[ptr->second]};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> vec_ans;
    for (auto val : ans)
    {
        vec_ans.push_back(val);
    }
    return vec_ans;
}

// ----------------meth3
vector<vector<int>> fourSum3(vector<int> &nums, int target)
{
    unordered_set<int> seen;
    set<multiset<int>> ans_set;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int lastNumber = target - (nums[i] + nums[j] + nums[k]);
                if (seen.count(lastNumber))
                    ans_set.emplace(multiset<int>{nums[i], nums[j], nums[k], lastNumber});
            }
        }
        seen.insert(nums[i]);
    }
    vector<vector<int>> ans(ans_set.size());
    for_each(begin(ans_set), end(ans_set), [&, i(0)](auto &el) mutable
             { ans[i++] = vector<int>(begin(el), end(el)); });
    return ans;
}
// --------------meth4---->two pointer
vector<vector<int>> fourSum4(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int l = j + 1, r = n - 1;
            int remain = target - nums[i] - nums[j];
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
    vector<int> arr{1, 0, -1, 0, -2, 2};
    int tar = 0;
    vector<vector<int>> ans = fourSum1(arr, tar);
    for (auto val : ans)
    {
        for (auto v : val)
            cout << v << " ";

        cout << endl;
    }
}
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
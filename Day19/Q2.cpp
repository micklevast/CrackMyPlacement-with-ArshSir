#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    if (n < 3 || nums[0] > 0)
        return ans;
    else
    {
        for (int i = 0; i < n; i++)
        {
            int l = i + 1;
            int r = n - 1;
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
            { // If number is getting repeated, ignore the lower loop and continue.
                continue;
            }
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int last_low_occurence = nums[l], last_high_occurence = nums[r]; // Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and num[high] respectively
                    while (l < r && nums[l] == last_low_occurence)
                    { // Update the low and high with last occurences of low and high.
                        l++;
                    }
                    while (l < r && nums[r] == last_high_occurence)
                    {
                        r-- --;
                    }
                }
                else if (sum > 0)
                {
                    r--;
                }
                else if (sum < 0)
                {
                    l++;
                }
            }
        }
        return ans;
    }
}

int main()
{
    vector<int> ans;
    vector<int> nums{-1, 0, 1, 2, -1, -4};

    ans = threeSum(nums);
    cout << endl;
    for (auto val : ans)
        cout << val << " ";
}
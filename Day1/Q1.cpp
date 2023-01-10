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
int findDuplicate(vector<int> &nums) //-->TC: O(n) & SC: O(n)-->without modifying original array
{
    int n = nums.size();
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.find(nums[i]) == st.end())
            st.insert(nums[i]);
        else
            return nums[i];
    }
    return -1;
}

int findDuplicate1(vector<int> nums) //-->TC: O(n) & SC: O(1)-->modifying original array
{
    // since all number are in range [1....n]-->set each first occurance to -ve val and check if it is alrewady -neg then returnn that value
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        int val = nums[i];
        int id = abs(val);
        if (nums[id] < 0)
            return id;
        else
            nums[id] = -nums[id];
    }

    return -1;
}
int findDuplicate2(vector<int> nums) //-->TC: O(n) & SC: O(n)-->modifying original array
{
    int len = nums.size();
    vector<int> cnt(len + 1);
    for (int i = 0; i < len; i++)
    {
        cnt[nums[i]]++;
        if (cnt[nums[i]] > 1)
        {
            return nums[i];
        }
    }

    return len;
}
int findDuplicate3(vector<int> &nums) //-->TC: O(nlog(n)) & SC: O(1)-->without modifying original array
{
    int len = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 1; i < len; i++)
    {
        if (nums[i] == nums[i - 1])
            return nums[i];
    }

    return len;
}
int main()
{
    vector<int> num{1, 2, 6, 5, 4, 3, 6};
    cout << findDuplicate(num) << endl;
    cout << findDuplicate1(num) << endl;
    cout << findDuplicate2(num) << endl;
    cout << findDuplicate3(num) << endl;
}
#include <vector>
#include <iostream>
#define ll long long int
// meth1---------
int reversePairs(vector<int> nums)
{
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long a = nums[i];
            long long b = nums[j];
            if (a > (b * 2))
                ans++;
        }
    }
    return ans;
}

int main()
{
}
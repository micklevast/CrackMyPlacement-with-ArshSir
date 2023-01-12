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
int subarraysDivByK(vector<int> &nums, int k)
{
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int sum = nums[i];
        if (sum % k == 0)
        {
            ans++;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (sum % k == 0)
            {
                ans++;
            }
            sum += nums[j];
        }
    }
    return ans;
}
int main()
{
    vector<int> arr{4, 5, 0, -2, -3, 1};
    int k = 5;
    cout << subarraysDivByK(arr, k) << endl;
}
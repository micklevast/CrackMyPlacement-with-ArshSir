#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[n] = 0;
        for (int i = n - 1; i > 0; i--)
        {
            int jmp = nums[i - 1];
            // cout<<"jmp:"<<jmp<<endl;
            int minj = INT_MAX - 1;
            int j = 1;
            while (j <= jmp && i + j <= n)
            {
                // cout<<"vall:"<<i<<endl;
                minj = min(minj, dp[i + j]);
                j++;
            }
            dp[i] = minj + 1;
        }
        // for (auto val : dp)
        //     cout << val << "  ";
        return dp[1];
    }
};
int main()
{
    vector<int> arr{2, 1, 3, 1, 0, 3};
    // for (int i = 0; i < 5; i++)
    //     cin >> arr[i];

    Solution s;
    cout << s.jump(arr) << endl;
}
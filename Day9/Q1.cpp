
#include <vector>
#include <iostream>
#define ll long long int
using namespace std;
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        int totalSum = 0;
        int currMaxSum = 0;
        int currMinSum = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;

        for (int a : A)
        {
            totalSum += a;
            currMaxSum = max(currMaxSum + a, a);
            currMinSum = min(currMinSum + a, a);
            maxSum = max(maxSum, currMaxSum);
            minSum = min(minSum, currMinSum);
        }

        return maxSum < 0 ? maxSum : max(maxSum, totalSum - minSum);
    }
};
int main()
{
    Solution s;
    vector<int> arr{1, 3, -5, 6, -2};
    cout << s.maxSubarraySumCircular(arr);
}
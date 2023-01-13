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
class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {
        int n = arr.size(); // taking the size of the array

        int ans = 0; // ans variable to store our count

        for (int i = 0; i < n; i++) // traverse from the array
        {
            int sum = arr[i]; // provide sum with arr[i]

            if (sum == k) // if element itself equal to k, then also increment count
                ans++;

            for (int j = i + 1; j < n; j++) // now moving forward,
            {
                sum += arr[j]; // add elements with sum

                if (sum == k) // if at any point they become equal to k
                    ans++;    // increment answer
            }
        }

        return ans; // and at last, return answer
    }
};
int main()
{
    Solution s;
    s.subarraySum({45, 23, 6, 98, 61, 6}, 5);
}
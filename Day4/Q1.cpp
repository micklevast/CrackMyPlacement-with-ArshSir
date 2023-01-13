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
    int maxArea(vector<int> &height)
    { // O(n)
        int left = 0;
        int right = height.size() - 1;
        int maxi = 0;
        while (left < right)
        {
            int w = right - left;
            int h = min(height[left], height[right]);
            int area = h * w;
            maxi = max(maxi, area);
            if (height[left] < height[right])
                left++;
            else if (height[left] > height[right])
                right--;
            else
            {
                left++;
                right--;
            }
        }
        return maxi;
    }
};
int main()
{
    vector<int> hgt{1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << "amx area ans:" << s.maxArea(hgt) << endl;
}
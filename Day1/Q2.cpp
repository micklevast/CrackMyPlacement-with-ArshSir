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
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int l = 0, r = n - 1, i = 0;
    while (i <= r)
    {
        if (nums[i] == 0)
        {
            swap(nums[i], nums[l]);
            l++;
            i++;
        }
        else if (nums[i] == 1)
        {
            i++;
        }
        else if (nums[i] == 2)
        {
            swap(nums[i], nums[r]);
            r--;
        }
    }
}
int main()
{
    vector<int> color{2, 0, 1, 1, 0, 2, 0, 1};
    sortColors(color);
    for (int i = 0; i < color.size(); i++)
    {
        cout << color[i] << " ";
    }
}
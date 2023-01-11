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
void moveZeroes(vector<int> &nums)
{
    int k = 0;
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        if (nums[i] > 0)
        {
            swap(nums[k++], nums[i++]);
        }
        else
            i++;
    }
}
int main()
{
    vector<int> arr{0, 1, 0, 3, 12};
    moveZeroes(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
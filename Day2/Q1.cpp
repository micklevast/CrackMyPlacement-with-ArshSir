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
int removeDuplicates(vector<int> &nums)
{
    set<int> st;
    int j = 1;
    st.insert(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        st.insert(nums[i]);
        if (nums[i] != nums[i - 1])
        {
            nums[j++] = nums[i];
        }
    }
    //    cout<<"ans:"<<st.size()<<endl;
    return st.size();
}
int removeDuplicates2(vector<int> &nums)
{
    int j = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
            continue;
        else
        {
            nums[j++] = nums[i];
        }
    }
    return j;
}
int main()
{
    vector<int> arr{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates2(arr) << endl;
    cout << removeDuplicates(arr) << endl;
}
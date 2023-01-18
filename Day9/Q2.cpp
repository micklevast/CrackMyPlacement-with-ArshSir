#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#define ll long long int
using namespace std;
class Solution
{
public:
    void makePrevSmall(vector<int> &preSmall, vector<int> hgt)
    {
        stack<int> st;
        for (int i = 0; i < hgt.size(); i++)
        {
            while (!st.empty() && hgt[st.top()] >= hgt[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                preSmall[i] = st.top();
            }
            else
            {
                preSmall[i] = -1;
            }
            st.push(i);
        }
    }
    void makeNextSmall(vector<int> &nextSmall, vector<int> hgt)
    {
        stack<int> st;
        int i = hgt.size() - 1;
        for (; i >= 0; i--)
        {
            while (!st.empty() && hgt[st.top()] >= hgt[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                nextSmall[i] = st.top();
            }
            else
            {
                nextSmall[i] = hgt.size();
            }
            st.push(i);
        }
    }
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int largestRectangleArea(vector<int> &hgt)
    {
        int n = hgt.size();
        vector<int> preSmall(n), nextSmall(n);
        makePrevSmall(preSmall, hgt);
        makeNextSmall(nextSmall, hgt);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int area;
            if (preSmall[i] != -1)
                area = (nextSmall[i] - preSmall[i] - 1) * hgt[i];
            else
                area = (nextSmall[i] - 0) * hgt[i];
            ans = max(ans, area);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr{2, 1, 5, 3, 6, 4};
    cout << s.largestRectangleArea(arr) << endl;
}
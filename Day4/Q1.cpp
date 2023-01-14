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
    int maxArea(vector<int> &hgt)
    {
        int ans = INT_MIN;
        int n = hgt.size();
        for (int i = 0; i < n; i++)
        {
            int la = 0;
            int ra = 0;
            int li = i - 1;
            int ri = i + 1;
            int area = 0;
            while (ri < n)
            {
                area = max(area, ((ri - i) * min(hgt[i], hgt[ri])));
                ri++;
            }
            while (li >= 0)
            {
                area = max(area, ((i - li) * min(hgt[i], hgt[li])));
                li--;
            }
            ans = max(ans, area);
        }
        return ans;
    }
    int min(int a, int b)
    {
        return a > b ? b : a;
    }
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int maxArea1(vector<int> &hgt)
    {
        int ans = INT_MIN;
        int n = hgt.size() - 1;
        int i = 0;
        while (i < n)
        {
            ans = max(ans, ((n - i) * min(hgt[n], hgt[i])));
            //    cout<<"i:"<<i<<" n:"<<n<<"  ans:"<<ans<<endl;
            if (hgt[i] < hgt[n])
            {
                i++;
            }
            else if (hgt[i] > hgt[n])
            {
                n--;
            }
            else
            {
                i++;
                n--;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> hgt{1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << "amx area ans:" << s.maxArea(hgt) << endl;
}
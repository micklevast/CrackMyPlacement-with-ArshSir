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

https : // www.geeksforgeeks.org/chocolate-distribution-problem/-->solve again
        int
        main()
{
    vector<int> choc{3, 4, 1, 9, 56, 7, 9, 12};
    int k = 5;
    sort(choc.begin(), choc.end());
    if (choc.size() < k)
        return -1;
    else if (choc.size() - 1 == k)
        return choc[choc.size() - 1] - choc[0];
    else
    {
        int ans = INT_MAX;
        for (int i = 1; i < k; i++)
        {
            if (choc[i] - choc[i - 1] < ans)
                ans = choc[i] - choc[i - 1];
        }
        cout << ans << endl;
    }
}
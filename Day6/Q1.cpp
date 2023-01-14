#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <map>
#define ll long long int
using namespace std;
// ---------got somewhere wrong-------------
int maxScore(vector<int> &cP, int k)
{
    int i = 0;
    int j = cP.size() - 1;
    int ans = 0;
    while (k > 0 && i <= j)
    {
        if (cP[i] > cP[j])
        {
            ans += cP[i++];
            cout << "i:" << i << "  done\n";
        }
        else if (cP[i] < cP[j])
        {
            ans += cP[j--];
            cout << "j:" << j << "  done\n";
        }
        else
        {
            ans += cP[i];

            // if(i+1<j && j-1>i)
            // {
            if (cP[i + 1] > cP[j - 1])
                i++;
            else
                j--;
            // }
            // else return ans;
            // if(j<=i)ans+=cP[j+1];
            cout << "i:" << i << "  j:" << j << "  done\n";
        }
        k--;
    }
    return ans;
}
// --------------------meth2------------------
int max(int a, int b)
{
    return a > b ? a : b;
}
int maxScore2(vector<int> &cP, int k)
{
    int i = 0;
    int j = cP.size() - 1;
    int ans = 0;
    int max_ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += cP[i];
    }
    max_ans = max(ans, max_ans);
    while (k > 0)
    {
        ans -= cP[k - 1];
        k--;
        ans += cP[j--];
        max_ans = max(ans, max_ans);
    }
    return max_ans;
}

int main()
{
    vector<int> cardPoint{1, 2, 3, 4, 5, 6, 1};
    int k = 4;
    cout << maxScore2(cardPoint, k);
}
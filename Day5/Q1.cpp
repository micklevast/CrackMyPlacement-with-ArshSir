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
int getPairsCount1(int arr[], int n, int k)
{
    // code here
    int i = 0, j = n - 1;
    int ans = 0;
    sort(arr, arr + n);
    while (i < j) // O(N)
    {
        if (arr[i] + arr[j] == k)
        {
            ans++;
            int ii = i + 1, jj = j - 1;
            while (ii < j && arr[ii] == arr[i])
            {
                ans++;
                ii++;
            }
            // jj--;
            while (jj > i && arr[jj] == arr[j])
            {
                ans++;
                jj--;
            }
            i = ii;
            j = jj;
        }
        else if (arr[i] + arr[j] > k)
            j--;
        else if (arr[i] + arr[j] < k)
            i++;
    }
    return ans;
}
int getPairsCount(int arr[], int n, int k) // TC-->O(n)  & SC--> O(n)  -->More accurate
{
    // code here
    int i = 0, j = n - 1;
    int ans = 0;
    unordered_map<int, int> p;
    for (int i = 0; i <= j; i++)
    {
        int val = arr[i];
        if (p.find(k - val) != p.end())
        {
            // cout<<"val:"<<k-val<<"  founded\n";
            ans += p[k - val];
        }
        p[val]++;
    }

    return ans;
}

int getPairsCount2(int arr[], int n, int k) // TC-->O(n)  & SC--> O(n)  -->More accurate
{
    // code here
    int i = 0, j = n - 1;
    int ans = 0;
    unordered_map<int, int> p;
    for (int i = 0; i <= j; i++)
    {
        p[arr[i]]++;
    }
    // for (auto val : p)
    //     cout << val.first << " ->" << val.second << endl;
    for (auto val : p)
    {
        int rs = k - val.first;
        if (rs < 0)
            continue;
        int freq = p[val.first];
        if (val.second > 1)
        {
            p[val.first]--;
        }
        else
        {
            p.erase(p.find(val.first));
        }

        if (p.find(rs) != p.end())
        {
            ans += (freq * p[rs]);
            p.erase(p.find(rs));
            // if (p.find(rs) == p.end())
            //     cout << rs << " delected with:" << val.first << endl;
        }
    }

    return ans;
}
int main()
{
    // int arr[] = {48, 24, 99, 51, 33, 39, 29, 83, 74, 72, 22, 46, 40, 51, 67, 37, 78, 76, 26, 28, 76, 25, 10, 65, 64, 47, 34, 88, 26, 49, 86, 73, 73, 36, 75, 5, 26, 4, 39, 99, 27, 12, 97, 67, 63, 15, 3, 92, 90};
    int arr[] = {1, 5, 7, 1};
    int n = 4;
    int k = 6;

    // cout << getPairsCount1(arr, 5, 6) << endl;
    cout << getPairsCount(arr, n, k) << endl;
    cout << getPairsCount2(arr, n, k) << endl;
}
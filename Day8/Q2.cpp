#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> sum(n);
        int max = INT_MIN, min = INT_MAX;
        int ttl = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (max < arr[i])
                max = arr[i];
            if (min > arr[i])
                min = arr[i];
        }
        if (min == max)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            cout << max << " " << min << " ";
            sort(arr.begin(), arr.end());
            for (int i = 1; i < n - 1; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
}
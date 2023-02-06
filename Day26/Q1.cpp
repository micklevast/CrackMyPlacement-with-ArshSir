#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        int is_exit_nq = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (sqrt(arr[i]) != int(sqrt(arr[i])))
            {
                is_exit_nq++;
            }
        }
        if (is_exit_nq)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
        // cout << sqrt(n) << endl;
        // cout << int(sqrt(n)) << endl;
    }
}
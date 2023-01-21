//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#define ll long long int
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    priority_queue<int> q;                             // maxheap
    priority_queue<int, vector<int>, greater<int>> q1; // minheap
                                                       // Function to insert heap.
    void insertHeap(int &x)
    {
        if (q.size() == 0 && q1.size() == 0)
        {
            q.push(x);
        }
        else
        {
            if (q.top() >= x)
            {
                q.push(x);
                balanceHeaps();
            }
            else
            {
                q1.push(x);
                balanceHeaps();
            }
        }
    }

    // Function to balance heaps.
    void balanceHeaps()
    {
        if (q1.size() - q.size() > 1)
        {
            q.push(q1.top());
            q1.pop();
        }
        if (q.size() - q1.size() > 1)
        {
            q1.push(q.top());
            q.pop();
        }
    }

    // Function to return Median.
    double getMedian()
    {
        if (q.size() == 0 && q1.size() == 0)
            return 0;
        else if (q.size() > q1.size())
            return q.top();
        else if (q.size() < q1.size())
            return q1.top();
        else
        {
            return (q.top() + q1.top()) / 2.0;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    // return 0;
    // priority_queue<int> q;                             // maxheap
    // priority_queue<int, vector<int>, greater<int>> q1; // minheap
    // q1.push(45);
    // q1.push(95);
    // q1.push(2);
    // q.push(45);
    // q.push(95);
    // q.push(2);
    // while (q.size() > 0)
    // {
    //     cout << q.top() << " ";
    //     q.pop();
    // }
    // cout << endl;
    // while (q1.size() > 0)
    // {
    //     cout << q1.top() << " ";
    //     q1.pop();
    // }
}
// } Driver Code Ends
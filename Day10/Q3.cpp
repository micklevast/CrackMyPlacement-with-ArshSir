#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#define ll long long int
using namespace std;
int mini(int a, int b)
{
    return a > b ? b : a;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int w, dd, h;
        int a, b, c, d;
        cin >> w >> dd >> h;
        cin >> a >> b >> c >> d;
        int d1 = w - a + w - c + abs(b - d);
        int d2 = a + c + abs(b - d);
        int d3 = b + d + abs(a - c);
        int d4 = dd - b + dd - d + abs(a - c);
        int mini = min(min(d1, d2), min(d3, d4));
        cout << mini + abs(h) << endl;
    }
}
#include <iostream>
using namespace std;

int findMax(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int findMin(int x, int y)
{
    if (x < y)
        return x;
    else
        return y;
}

int main()
{
    int n, d, count=0, t=0;
    cin >> n >> d;
    for (int i = 0, a, b, c; i < n; i++)
    {
        cin >> a >> b >> c;
        int mx = findMax(a, findMax(b, c));
        int mn = findMin(a, findMin(b, c));
        if (mx - mn >= d)
        {
            count++;
            t += (a + b + c) / 3;
        }
    }
    cout << count << " " << t << "\n";
}
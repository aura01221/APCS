#include <iostream>
using namespace std;

int main()
{
    int m, n, a[10005], l[10005], r[10005];
    int myMap[55][10000] = {0};
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[j];
            if (j == 1)
                l[j] = myMap[i - 1][j] + a[j];
            else
                l[j] = max(myMap[i - 1][j], l[j - 1]) + a[j];
        }
        for (int j = n; j >= 1; j--)
        {
            if (j == n)
                r[j] = myMap[i - 1][j] + a[j];
            else
                r[j] = max(myMap[i - 1][j], r[j + 1]) + a[j];
            myMap[i][j] = max(l[j], r[j]);
        }
    }
    int ans = -1e9;
    for (int j = 1; j <= n; j++)
    {
        ans = max(ans, myMap[m][j]);
    }
    cout << ans << "\n";
    system("pause");
}
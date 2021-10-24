#include <iostream>
using namespace std;
int main()
{
    int a1, b1, c1, a2, b2, c2, n, x1, x2, y1, y2, ans = -1000000;
    //輸入
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> n;
    //執行n次
    for (x1 = 0; x1 <= n; x1++)
    {
        x2 = n - x1;
        y1 = a1 * x1 * x1 + b1 * x1 + c1;
        y2 = a2 * x2 * x2 + b2 * x2 + c2;
        if (ans < y1 + y2)
            ans = y1 + y2;
    }
    //輸出結果
    cout << ans << endl;
    return 0;
}
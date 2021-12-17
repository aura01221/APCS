#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 0, c = 0, d = 0, n;
    for (int i = 0; i < 4; i++)
    {
        cin >> n;
        a += n;
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> n;
        b += n;
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> n;
        c += n;
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> n;
        d += n;
    }
    cout << a << ":" << b << "\n";
    cout << c << ":" << d << "\n";
    if (a > b && c > d)
        cout << "Win\n";
    else if (a < b && c < d)
        cout << "Lose\n";
    else
        cout << "Tie\n";
}
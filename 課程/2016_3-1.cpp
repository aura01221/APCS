#include <iostream>
using namespace std;

int main()
{
    int best = -1;
    int worst = 101;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < 60)
        {
            if (best < a[i])
                best = a[i];
        }
        else
        {
            if (worst > a[i])
                worst = a[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << " ";
        cout << a[i];
    }
    cout << "\n";
    if (best < 0)
        cout << "best case\n";
    else
        cout << best << "\n";
    if (worst > 100)
        cout << "worst case\n";
    else
        cout << worst << "\n";
    return 0;
}
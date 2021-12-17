#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int sum = 0;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        int x, mx = 0;
        for (int j = 0; j < M; j++)
        {
            cin >> x;
            if (x > mx)
            {
                mx = x;
            }
        }
        a[i] = mx;
        sum += mx;
    }
    cout << sum << endl;
    int cnt = 0;
    int i = 0;
    for (i = 0; i < N; i++)
    {
        if (sum % a[i] == 0)
        {
            cnt++;
            cout << a[i];
            break;
        }
    }
    for (i++; i < N; i++)
    {
        if (sum % a[i] == 0)
        {
            cnt++;
            cout << ' ' << a[i];
        }
    }
    if (!cnt)
    {
        cout << "-1" << endl;
    }
    return 0;
}
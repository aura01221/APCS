#include <iostream>
using namespace std;

int main()
{
    int fr[50005];
    int group[50005];
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> fr[i];
        group[i] = -1;
    }
    for (int i = 0; i < N; i++)
    {
        if (group[i] >= 0)
            continue;
        group[i] = i;
        int now = i;
        while (fr[now] != i)
        {
            group[fr[now]] = i;
            now = fr[now];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += (group[i] == i);
    }
    cout << ans << '\n';

    return 0;
}
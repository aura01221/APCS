#include <iostream>
using namespace std;

int find(int n, int m, int k)
{
    int num;
    for (int i = n - k + 1; i <= n; i++)
    {
        num = (num + m) % i;
    }
    return num;
}

int main()
{
    int N, M, K;
    while (cin >> N >> M >> K)
    {
        int ans = find(N, M, K)+1;
        cout << ans << '\n';
    }

    return 0;
}
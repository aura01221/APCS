#include <iostream>
using namespace std;

int main()
{
    int N, nxt;
    while (cin >> N)
    {
        cin >> nxt;
        int a[N][N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> a[i][j];
            }
        }
        // 0左、1上、2右、3下
        int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int total_steps = N * N, steps = 1;
        int repeat = 1, repeat_cnt = 0;
        int r = N / 2, c = N / 2; // 從中心點出發

        cout << a[r][c];
        while (steps < total_steps)
        {
            for (int i = 0; i < repeat; i++)
            {
                r += dir[nxt][0];
                c += dir[nxt][1];
                cout << a[r][c];
                steps++;
                if (steps == total_steps)
                    break;
            }

            repeat_cnt++;
            if (repeat_cnt % 2 == 0)
                repeat++;
            nxt = (nxt + 1) % 4;
        }
        cout << endl;
    }
    return 0;
}
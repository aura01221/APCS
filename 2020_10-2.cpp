#include <iostream>
using namespace std;

const int dirX[4] = {-1, 0, 1, 0}; //left up right down
const int dirY[4] = {0, -1, 0, 1}; // 0   1    2    3

int max(int, int);
int min(int, int);

int main(void)
{
	int r, c, k, m;
	int city[52][52];
	int move[52][52];
	cin >> r >> c >> k >> m;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> city[i][j];
		}
	}
	for (int i = 0; i < 52; i++)
	{
		city[0][i] = -1;
		city[i][0] = -1;
	}
	for (int i = 1; i <= r + 1; i++)
	{
		city[i][c + 1] = -1;
	}
	for (int i = 1; i <= c + 1; i++)
	{
		city[r + 1][i] = -1;
	}
	int neighbor;
	for (int day = 1; day <= m; day++)
	{ //repeat for m days
		//empty move arr
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				move[i][j] = 0;
			}
		}
		//move in & out
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				neighbor = 0;
				for (int dir = 0; dir <= 3; dir++)
				{ //find neighbors
					if (city[i + dirY[dir]][j + dirX[dir]] != -1)
					{
						neighbor++;
						move[i + dirY[dir]][j + dirX[dir]] += city[i][j] / k;
					}
				}
				move[i][j] -= city[i][j] / k * neighbor;
			}
		}

		//update
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				city[i][j] += move[i][j];
			}
		}

		for (int i = 0; i <= r; i++)
		{
			for (int j = 0; j <= c; j++)
			{
				cout << city[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}

	//search for max & min
	int maximum = 0;
	int minimum = 1000;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (city[i][j] != -1)
			{
				maximum = max(maximum, city[i][j]);
				minimum = min(minimum, city[i][j]);
			}
		}
	}

	//print
	printf("%d\n%d\n", minimum, maximum);
	system("pause");
	return 0;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
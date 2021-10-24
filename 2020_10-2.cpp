#include <iostream>
using namespace std;

int main()
{
	int r, c, k, m;
	int city[52][52];
	int move[52][52];
	cin >> r >> c >> k >> m;
	//輸入一開始人數
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> city[i][j];
		}
	}
	//建立牆壁
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
	//重複m天
	for (int day = 1; day <= m; day++)
	{ 
		//清空move array
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				move[i][j] = 0;
			}
		}
		//計算遷移人數
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				neighbor = 0;
				if (city[i-1][j] != -1)
				{
					neighbor++;
					move[i-1][j] += city[i][j] / k;
				}
				if (city[i][j] != -1)
				{
					neighbor++;
					move[i+1][j] += city[i][j] / k;
				}
				if (city[i][j-1] != -1)
				{
					neighbor++;
					move[i][j-1] += city[i][j] / k;
				}
				if (city[i][j+1] != -1)
				{
					neighbor++;
					move[i][j+1] += city[i][j] / k;
				}
				move[i][j] -= city[i][j] / k * neighbor;
			}
		}

		//更新city
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				city[i][j] += move[i][j];
			}
		}
	}

	//找出最大和最小的人數
	int maximum = 0;
	int minimum = 10000;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (city[i][j] != -1)
			{
				if(maximum<city[i][j]){
					maximum=city[i][j];	
				}
				if(minimum>city[i][j]){
					minimum=city[i][j];	
				}
			}
		}
	}
	//輸出
	cout<<minimum<<endl<<maximum<<endl;
	return 0;
}

#include <iostream>
#include <deque>

using namespace std;
int arr[200 + 2][200 + 2];
int X = 1, Y = 1;
int S = 0;
deque <pair<int,int>> Q;
bool vicinity_bigger(int x, int y)
{
	int val = arr[x][y];
	if (val >= arr[x + 1][y] && val >= arr[x - 1][y] && val >= arr[x][y + 1] && val >= arr[x][y - 1])
		return true;
	else return false;
}
bool func()
{
	int x = Q.front().first;
	int y = Q.front().second;
	Q.pop_front();
	int val = arr[x][y];
	if (arr[x + 1][y] == 0 && vicinity_bigger(x + 1, y))
	{
		arr[x + 1][y] = val;
		Q.push_back(make_pair(x + 1, y));
	}
	if (arr[x - 1][y] == 0 && vicinity_bigger(x - 1, y))
	{
		arr[x - 1][y] = val;
		Q.push_back(make_pair(x - 1, y));
	}
	if (arr[x][y + 1] == 0 && vicinity_bigger(x, y + 1))
	{
		arr[x][y + 1] = val;
		Q.push_back(make_pair(x, y + 1));
	}
	if (arr[x][y - 1] == 0 && vicinity_bigger(x, y - 1))
	{
		arr[x][y - 1] = val;
		Q.push_back(make_pair(x, y - 1));
	}
}
void set()
{
	int N = 5;
	cin >> N; cin >> S >> X >> Y;
	int** arr = new int* [N];
	for (int i = 0; i < N + 2; i++)
		arr[i] = new int[N];
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] != 0)
				Q.push_back(make_pair(i, j));
		}
	// 2차원 동적배열 초기화
	for (int i = 0; i < N + 2; i++) arr[i][0] = -1;
	for (int i = 0; i < N + 2; i++) arr[0][i] = -1;
	for (int i = 0; i < N + 2; i++) arr[N + 1][i] = -1;
	for (int i = 0; i < N + 2; i++) arr[i][N + 1] = -1;
}
int main()
{
	set();
	while (S)
	{
		func();

		S--;
	}

	return 0;
}
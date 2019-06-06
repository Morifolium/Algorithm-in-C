#include <iostream>
#define MAX 2001


int mp[MAX][MAX], dp[MAX][MAX];
int n, m;
int main()
{
	scanf("%d%d", &n, &m);
	int square(int a);
	int max(int a, int b);
	int min(int a, int b);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &mp[i][j]);
			if ((i + j) % 2 == 0)
			{
				mp[i][j] = !mp[i][j];
			}
		}
	}
	int s1s = 0, s0s = 0, maxs = 0;
	s1s = square(1);
	s0s = square(0);
	maxs = max(s1s, s0s);
	maxs *= maxs;
	printf("%d", maxs);
}
int square(int a)
{
	int res = 1;
	int min(int a, int b);
	int max(int a, int b);
	for (int i = 0; i < n; i++) {
		if (mp[i][0] == a) {
			dp[i][0] = 1;
		}
	}

	for (int j = 0; j < m; j++) {
		if (mp[0][j] == a) {
			dp[0][j] = 1;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (mp[i][j] == a) {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
			res = max(res, dp[i][j]);
		}
	}
	return res;
}
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int min(int a, int b)
{
	if (a < b)return a;
	else return b;
}

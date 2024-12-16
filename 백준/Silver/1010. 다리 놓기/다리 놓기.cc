#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t, n, m;
	cin >> t;

	vector< vector<int> > dp(31, vector<int>(31));
	for (int i = 0; i < 31; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
		dp[i][i] = 1;
	}
	for (int i = 1; i < 31; i++) {
		for (int j = 1; j < i; j++)
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
	}

	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cout << dp[m][n] << "\n";
	}

	return 0;
}

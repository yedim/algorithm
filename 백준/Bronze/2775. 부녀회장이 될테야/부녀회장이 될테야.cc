#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t, k, n;
	cin >> t;

	vector< vector<int> > dp(15, vector<int>(15));
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (i == 0)
				dp[i][j] = j;
			else if (j == 1)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	for (int i = 0; i < t; i++) {
		cin >> k >> n;
		cout << dp[k][n] << "\n";
	}

	return 0;
}

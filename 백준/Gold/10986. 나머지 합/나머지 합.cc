#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<long long> cnt(m, 0);
	long long num,  sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		sum += num;
		cnt[sum % m]++;
	}

	long long result = 0;
	result += cnt[0];
	for (int i = 0; i < m; i++) {
		if (cnt[i] >= 2)
			result += cnt[i] * (cnt[i] - 1) / 2;
	}

	cout << result << "\n";

	return 0;
}

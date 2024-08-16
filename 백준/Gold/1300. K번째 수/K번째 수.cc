#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	int start = 1, end = k, result = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (mid / i > n)
				cnt += n;
			else
				cnt += mid / i;
		}

		if (cnt < k)
			start = mid + 1;
		else {
			end = mid - 1;
			result = mid;
		}
	}

	cout << result << "\n";

	return 0;
}

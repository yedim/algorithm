#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int start = 1, end = 1, sum = 1, cnt = 1;
	while (end != n) {
		if (sum <= n) {
			if (sum == n)
				cnt++;
			end++;
			sum += end;
		} else if (sum > n) {
			sum -= start;
			start++;
		}
	}

	cout << cnt << "\n";

	return 0;
}

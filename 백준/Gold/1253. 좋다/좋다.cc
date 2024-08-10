#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<long long> num(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());

	int result = 0;
	for (int k = 0; k < n; k++) {
		int i = 0, j = n - 1;
		while (i < j) {
			long long sum = num[i] + num[j];
			if (sum == num[k] && i != k && j != k) {
				result++;
				break;
			} else if (sum > num[k] || j == k)
				j--;
			else if (sum < num[k] || i == k)
				i++;
		}
	}

	cout << result << "\n";

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	vector<int> sum(n);
	sum[0] = v[0];
	int result = sum[0];
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + v[i];
		result += sum[i];
	}

	cout << result << "\n";

	return 0;
}

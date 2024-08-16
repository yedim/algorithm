#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (k < v[i])
			continue;
		cnt += k / v[i];
		k = k % v[i];
	}

	cout << cnt << "\n";

	return 0;
}

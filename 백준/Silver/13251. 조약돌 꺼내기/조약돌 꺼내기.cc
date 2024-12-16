#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0, m, k;
	double ans = 0;
	cin >> m;

	vector<int> color(m);
	for (int i = 0; i < m; i++) {
		cin >> color[i];
		n += color[i];
	}

	cin >> k;

	for (int i = 0; i < m; i++) {
		if (color[i] >= k) {
			double tmp = 1;
			for (int j = 0; j < k; j++) {
				tmp *= (double)(color[i] - j) / (n - j);
			}
			ans += tmp;
		}
	}

	cout << fixed;
	cout.precision(9);
	cout << ans << "\n";

	return 0;
}

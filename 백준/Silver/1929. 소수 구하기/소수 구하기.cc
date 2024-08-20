#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<bool> v(m + 1, true);
	v[1] = false;
	for (int i = 2; i <= sqrt(m); i++) {
		for (int j = i + i; j <= m; j+=i)
			v[j] = false;
	}

	for (int i = n; i <= m; i++) {
		if (v[i])
			cout << i << "\n";
	}

	return 0;
}

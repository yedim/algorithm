#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector< pair<int, int> > v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}

	sort(v.begin(), v.end());

	int max = v[0].second;
	for (int i = 1; i < n; i++) {
		int tmp = v[i].second - i;
		if (max < tmp)
			max = tmp;
	}

	cout << max + 1 << "\n";

	return 0;
}

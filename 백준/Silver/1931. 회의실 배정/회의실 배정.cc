#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector< pair<int, int> > v(n); // second: 시작 시간, first: 끝 시간
	for (int i = 0; i < n; i++)
		cin >> v[i].second >> v[i].first;
	
	sort(v.begin(), v.end());

	int cnt = 0, available = -1;
	for (int i = 0; i < n; i++) {
		if (available <= v[i].second) {
			available = v[i].first;
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}

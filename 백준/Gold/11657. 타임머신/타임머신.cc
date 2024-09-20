#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits.h>
using namespace std;

int main()
{
	int n, m, a, b, c;
	cin >> n >> m;

	vector< tuple<int, int, int> > v;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v.push_back({a, b, c});
	}

	vector<long> distance(n + 1, LONG_MAX);
	distance[1] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			int s = get<0>(v[j]);
			int e = get<1>(v[j]);
			int t = get<2>(v[j]);
			if (distance[s] != LONG_MAX && distance[e] > distance[s] + t)
				distance[e] = distance[s] + t;
		}
	}

	bool flag = false;
	for (int i = 0; i < m; i++) {
		int s = get<0>(v[i]);
		int e = get<1>(v[i]);
		int t = get<2>(v[i]);
		if (distance[s] != LONG_MAX && distance[e] > distance[s] + t)
			flag = true;
	}

	if (flag)
		cout << "-1\n";
	else {
		for (int i = 2; i <= n; i++) {
			if (distance[i] == LONG_MAX)
				cout << "-1\n";
			else
				cout << distance[i] << "\n";
		}
	}

	return 0;
}

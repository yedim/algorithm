#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, s, e, c;
	cin >> n >> m;

	vector< vector< pair<int, int> > > arr(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> c;
		arr[s].push_back({e, c});
	}
	cin >> s >> e;

	vector<int> result(n + 1, INT_MAX);
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
	pq.push({0, s});
	result[s] = 0;
	while (!pq.empty()) {
		pair<int, int> curr = pq.top();
		pq.pop();

		if (result[curr.second] < curr.first)
			continue;

		for (pair<int, int> next : arr[curr.second]) {
			if (result[next.first] > result[curr.second] + next.second) {
				result[next.first] = result[curr.second] + next.second;
				pq.push({result[next.first], next.first});
			}
		}
	}

	cout << result[e] << "\n";

	return 0;
}

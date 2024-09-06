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

	int V, E, K, u, v, w;
	cin >> V >> E >> K;

	vector< vector< pair<int, int> > > arr(V + 1);
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		arr[u].push_back({v, w});
	}

	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
	vector<int> distance(V + 1, INT_MAX);
	q.push({0, K});
	distance[K] = 0;
	while (!q.empty()) {
		pair<int, int> curr = q.top();
		q.pop();
		if (curr.first > distance[curr.second])
			continue;

		for (pair<int, int> next : arr[curr.second]) {
			if (distance[next.first] > distance[curr.second] + next.second) {
				distance[next.first] = distance[curr.second] + next.second;
				q.push({distance[next.first], next.first});
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (distance[i] != INT_MAX)
			cout << distance[i] << "\n";
		else
			cout << "INF\n";
	}

	return 0;
}

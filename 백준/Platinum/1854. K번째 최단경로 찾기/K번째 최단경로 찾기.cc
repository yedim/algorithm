#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k, a, b, c;
	cin >> n >> m >> k;

	vector< vector< pair<int, int> > > arr(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		arr[a].push_back({b, c});
	}

	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
	vector< priority_queue<int> > distance(n + 1);
	q.push({0, 1});
	distance[1].push(0);
	while (!q.empty()) {
		pair<int, int> curr = q.top();
		q.pop();

		for (int i = 0; i < arr[curr.second].size(); i++) {
			pair<int, int> next = arr[curr.second][i];
			int dist = curr.first + next.second;
			if (distance[next.first].size() < k) {
				distance[next.first].push(dist);
				q.push({dist, next.first});
			} else if (distance[next.first].top() > dist) {
				distance[next.first].pop();
				distance[next.first].push(dist);
				q.push({dist, next.first});
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (distance[i].size() == k)
			cout << distance[i].top() << "\n";
		else
			cout << "-1\n";
	}

	return 0;
}

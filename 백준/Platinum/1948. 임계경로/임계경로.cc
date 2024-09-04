#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b, t, s, e;
	cin >> n >> m;

	vector<int> indegree(n + 1, 0);
	vector< vector< pair<int, int> > > v(n + 1);
	vector< vector< pair<int, int> > > rv(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> t;
		v[a].push_back({b, t});
		rv[b].push_back({a, t});
		indegree[b]++;
	}

	cin >> s >> e;
	queue<int> q;
	q.push(s);
	vector<int> result(n + 1);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (pair<int, int> i : v[front]) {
			result[i.first] = max(result[front] + i.second, result[i.first]);
			indegree[i.first]--;
			if (indegree[i.first] == 0)
				q.push(i.first);
		}
	}
	cout << result[e] << "\n";

	int cnt = 0;
	vector<bool> visited(n + 1, false);
	q.push(e);
	visited[e] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (pair<int, int> i : rv[front]) {
			if (result[front] == result[i.first] + i.second) {
				cnt++;
				if (!visited[i.first]) {
					visited[i.first] = true;
					q.push(i.first);
				}
			}
		}
	}
	cout << cnt << "\n";

	return 0;
}

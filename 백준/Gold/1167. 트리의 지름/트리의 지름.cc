#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector< vector< pair<int, int> > > v;
vector<bool> visited;
vector<int> dist;

void bfs(int num)
{
	queue<int> q;
	q.push(num);

	while (!q.empty()) {
		int i = q.front();
		q.pop();
		visited[i] = true;

		for (int j = 0; j < v[i].size(); j++) {
			pair<int, int> tmp = v[i][j];
			if (!visited[tmp.first]) {
				q.push(tmp.first);
				dist[tmp.first] = dist[i] + tmp.second;
			}
		}
	}
}

int main()
{
	cin >> n;

	v.resize(n + 1);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		while (1) {
			int a, b;
			cin >> a;
			if (a == -1)
				break;
			cin >> b;
			v[tmp].push_back({a, b});
		}
	}

	visited = vector<bool>(n + 1, false);
	dist = vector<int>(n + 1, 0);
	bfs(1);

	int max = max_element(dist.begin(), dist.end()) - dist.begin();
	visited = vector<bool>(n + 1, false);
	dist = vector<int>(n + 1, 0);
	bfs(max);

	cout << *max_element(dist.begin(), dist.end()) << "\n";

	return 0;
}

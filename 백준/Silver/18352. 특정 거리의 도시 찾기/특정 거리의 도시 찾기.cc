#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector< vector<int> > arr;
vector<int> visited;
vector<int> result;
int n, m, k, x, a, b;

void bfs()
{
	queue<int> q;
	visited[x] = 1;
	q.push(x);

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		for (int i = 0; i < arr[front].size(); i++) {
			int next = arr[front][i];
			if (!visited[next]) {
				if (visited[front] == k)
					result.push_back(next);
				visited[next] = visited[front] + 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k >> x;

	arr.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
	}

	visited.resize(n + 1, 0);
	bfs();

	if (result.empty())
		cout << "-1\n";
	else {
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << "\n";
	}

	return 0;
}

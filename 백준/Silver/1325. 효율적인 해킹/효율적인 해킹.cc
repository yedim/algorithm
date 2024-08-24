#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, a, b;
vector< vector<int> > arr;
vector<bool> visited;
vector<int> result;

void bfs()
{

	for (int i = 1; i <= n; i++) {
		visited = vector<bool>(n + 1, false);
		queue<int> q;
		
		q.push(i);
		visited[i] = true;
		while (!q.empty()) {
			int front = q.front();
			q.pop();
			for (int j = 0; j < arr[front].size(); j++) {
				int next = arr[front][j];
				if (!visited[next]) {
					q.push(next);
					visited[next] = true;
					result[i]++;
				}
			}
		}
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[b].push_back(a);
	}

	result = vector<int>(n + 1, 0);
	bfs();

	int max = *max_element(result.begin(), result.end());
	for (int i = 1; i <= n; i++) {
		if (result[i] == max)
			cout << i << "\n";
	}

	return 0;
}

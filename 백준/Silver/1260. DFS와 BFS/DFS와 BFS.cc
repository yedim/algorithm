#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
vector<bool> visited;
vector< vector<int> > arr;

void dfs(int num)
{
	cout << num << " ";
	visited[num] = true;

	for (int i = 0; i < arr[num].size(); i++) {
		int tmp = arr[num][i];
		if (!visited[tmp])
			dfs(tmp);
	}
}

void bfs(int num)
{
	queue<int> q;

	q.push(num);
	visited[num] = true;

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << " ";

		for (int i = 0; i < arr[front].size(); i++) {
			int tmp = arr[front][i];
			if (!visited[tmp]) {
				q.push(tmp);
				visited[tmp] = true;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> v;

	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 1; i < n + 1; i++)
		sort(arr[i].begin(), arr[i].end());

	visited = vector<bool>(n + 1, false);
	dfs(v);
	cout << "\n";

	visited = vector<bool>(n + 1, false);
	bfs(v);
	cout << "\n";

	return 0;
}

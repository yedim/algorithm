#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector< vector<int> > tree;
vector<int> depth;
vector<int> parent;

void bfs(int k)
{
	vector<bool> visited(n + 1, false);
	queue<int> q;

	q.push(k);
	visited[k] = true;
	depth[k] = 0;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int next : tree[curr]) {
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				parent[next] = curr;
				depth[next] = depth[curr] + 1;
			}
		}
	}
}

int lca(int a, int b)
{
	while (depth[a] != depth[b]) {
		if (depth[a] > depth[b])
			a = parent[a];
		else
			b = parent[b];
	}

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, a, b;
	cin >> n;
	
	tree.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	depth.resize(n + 1);
	parent.resize(n + 1);
	bfs(1);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}

	return 0;
}

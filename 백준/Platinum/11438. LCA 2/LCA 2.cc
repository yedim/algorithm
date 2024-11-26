#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector< vector<int> > tree;
vector< vector<int> > parent;
vector<int> p;
vector<int> depth;
int n, maxdepth = 0, k = 0;

void bfs(int start)
{
	queue<int> q;
	vector<bool> visited(n + 1, false);
	q.push(start);
	visited[start] = true;
	
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int next : tree[curr]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				depth[next] = depth[curr] + 1;
				p[next] = curr;
				if (maxdepth < depth[next])
					maxdepth = depth[next];
			}
		}
	}
}

int lca(int a, int b)
{
	if (depth[a] > depth[b]) {
		int tmp = b;
		b = a;
		a = tmp;
	}

	for (int i = k - 1; i >= 0; i--) {
		if (pow(2, i) <= depth[b] - depth[a]) {
			if (depth[a] <= depth[parent[i][b]])
				b = parent[i][b];
		}
	}

	for (int i = k - 1; i >= 0 && a != b; i--) {
		if (parent[i][a] != parent[i][b]) {
			a = parent[i][a];
			b = parent[i][b];
		}
	}

	if (a != b)
		return parent[0][a];
	else
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
	p.resize(n + 1);
	bfs(1);

	int tmp = maxdepth;
	while (tmp >= 1) {
		tmp /= 2;
		k++;
	}

	parent = vector< vector<int> >(k, vector<int>(n + 1, 0));
	parent[0] = p;
	for (int i = 1; i < k; i++) {
		// p[k][n] = p[k - 1][p[k - 1][n]]
		for (int j = 1; j <= n; j++)
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}

	return 0;
}

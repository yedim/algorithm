#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > v;
vector<bool> visited;
vector<int> parent;

void dfs(int n)
{
	visited[n] = true;

	for (int i : v[n]) {
		if (!visited[i]) {
			parent[i] = n;
			dfs(i);
		}
	}
}

int main()
{
	int n, a, b;
	cin >> n;

	v.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	visited = vector<bool>(n + 1, false);
	parent.resize(n + 1);
	dfs(1);

	for (int i = 2; i <= n; i++)
		cout << parent[i] << "\n";

	return 0;
}

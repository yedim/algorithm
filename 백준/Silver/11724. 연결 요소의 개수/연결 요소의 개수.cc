#include <iostream>
#include <vector>
using namespace std;

vector< pair<int, int> > v;

void dfs(int i, vector<bool>& visited)
{
	if (visited[i]) return;
	visited[i] = true;
	
	for (int j = 0; j < v.size(); j++) {
		if (v[j].first == i && !visited[v[j].second])
			dfs(v[j].second, visited);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
		v.push_back({b, a});
	}

	vector<bool> visited(n + 1, false);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i, visited);
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}

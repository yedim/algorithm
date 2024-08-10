#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > v;
vector<bool> visited;

void dfs(int num, int cnt)
{
	if (cnt == 5) {
		cout << "1\n";
		exit(0);
	}
	
	visited[num] = true;
	for (int i = 0; i < v[num].size(); i++) {
		int tmp = v[num][i];
		if (!visited[tmp]) {
			dfs(tmp, cnt + 1);
		}
	}
	visited[num] = false;
}

int main()
{
	int n, m;
	cin >> n >> m;

	v.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	visited = vector<bool>(n, false);
	for (int i = 0; i < n; i++)
		dfs(i, 1);

	cout << "0\n";

	return 0;
}

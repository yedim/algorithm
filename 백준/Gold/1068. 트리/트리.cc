#include <iostream>
#include <vector>
using namespace std;

int n, m, root, del, cnt = 0;
vector< vector<int> > v;
vector<bool> visited;

void dfs(int node)
{
	int chk = 0;
	visited[node] = true;

	for (int i : v[node]) {
		if (!visited[i] && i != del) {
			chk++;
			dfs(i);
		}
	}
	if (chk == 0)
		cnt++;
}

int main()
{
	cin >> n;

	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (m == -1)
			root = i;
		else
			v[m].push_back(i);
	}

	cin >> del;
	if (del == root)
		cout << "0\n";
	else {
		visited = vector<bool>(n, false);
		dfs(root);
		cout << cnt << "\n";
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, m, a, b;
	cin >> n >> m;

	vector< vector<int> > v(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}

	vector<int> indegree(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < v[i].size(); j++)
			indegree[v[i][j]]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << " ";
		for (int i = 0; i < v[front].size(); i++) {
			int index = v[front][i];
			indegree[index]--;
			if (indegree[index] == 0)
				q.push(index);
		}
	}
	cout << "\n";

	return 0;
}

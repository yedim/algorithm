#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, tmp;
	cin >> n;

	vector<int> time(n + 1);
	vector< vector<int> > v(n + 1);
	vector<int> indegree(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> time[i] >> tmp;
		while (tmp != -1) {
			v[tmp].push_back(i);
			indegree[i]++;
			cin >> tmp;
		}
	}

	queue<int> q;
	vector<int> result(n + 1);
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			result[i] = time[i];
		}
	}

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i : v[front]) {
			result[i] = max(result[front] + time[i], result[i]);
			indegree[i]--;
			if (indegree[i] == 0)
				q.push(i);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << result[i] << "\n";

	return 0;
}

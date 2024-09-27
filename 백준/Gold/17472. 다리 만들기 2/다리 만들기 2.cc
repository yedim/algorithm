#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
vector< vector<int> > map;
vector< vector<bool> > visited;
vector< pair<int, int> > direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int num = 0;
vector< vector< pair<int, int> > > info(7);
vector<int> parent;

int find(int idx)
{
	if (idx == parent[idx])
		return idx;
	else
		return parent[idx] = find(parent[idx]);
}

void bfs(int i, int j)
{
	queue< pair<int, int> > q;
	q.push({i, j});
	visited[i][j] = true;
	map[i][j] = num;
	info[num].push_back({i, j});

	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();

		for (pair<int, int> dir : direction) {
			int next_i = curr.first + dir.first;
			int next_j = curr.second + dir.second;
			if (next_i < 0 || next_j < 0 || next_i >= n || next_j >= m)
				continue;
			if (!visited[next_i][next_j] && map[next_i][next_j] == 1) {
				visited[next_i][next_j] = true;
				map[next_i][next_j] = num;
				info[num].push_back({next_i, next_j});
				q.push({next_i, next_j});
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	map.resize(n);
	for (int i = 0; i < n; i++) {
		map[i].resize(m);
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}

	visited = vector< vector<bool> >(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && map[i][j] == 1) {
				num++;
				bfs(i, j);
			}
		}
	}

	priority_queue< tuple<int, int, int>, vector< tuple<int, int, int> >, greater< tuple<int, int, int> > > pq;
	parent.resize(num + 1);
	for (int k = 1; k <= num; k++) {
		parent[k] = k;
		for (pair<int, int> curr : info[k]) {
			int i = curr.first;
			int j = curr.second;
			int start_num = map[i][j];
			

			for (pair<int, int> dir : direction) {
				int len = 0;
				int tmp_i = i + dir.first;
				int tmp_j = j + dir.second;
				int end_num = start_num;

				while (tmp_i >= 0 && tmp_j >= 0 && tmp_i < n && tmp_j < m) {
					if (map[tmp_i][tmp_j] != 0) {
						end_num = map[tmp_i][tmp_j];
						break;
					}
					len++;
					tmp_i += dir.first;
					tmp_j += dir.second;
				}
				if (start_num != end_num && len > 1) {
					pq.push({len, start_num, end_num});
				}
			}
		}
	}

	int cnt = 0;
	int sum = 0;
	while (!pq.empty()) {
		tuple<int, int, int> curr = pq.top();
		pq.pop();

		int next_i = find(get<1>(curr));
		int next_j = find(get<2>(curr));
		if (next_i != next_j) {
			parent[next_j] = next_i;
			cnt++;
			sum += get<0>(curr);
		}
	}

	if (cnt == num - 1)
		cout << sum << "\n";
	else
		cout << "-1\n";

	return 0;
}

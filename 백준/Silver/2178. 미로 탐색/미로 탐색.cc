#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector< vector<int> > arr;
vector< vector<int> > visited;
vector< pair<int, int> > direction(4);

void bfs()
{
	queue< pair<int, int> > q;
	q.push({0, 0});
	visited[0][0] = 1;

	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int x = i + direction[k].first;
			int y = j + direction[k].second;
			if (x >= 0 && x < n && y >= 0 && y < m) {
				if (arr[x][y] == 1 && visited[x][y] == 0) {
					q.push({x, y});
					visited[x][y] = visited[i][j] + 1;
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	arr.resize(n);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		arr[i].resize(m);
		for (int j = 0; j < m; j++)
			arr[i][j] = str[j] - '0';
	}

	direction[0] = {1, 0};
	direction[1] = {-1, 0};
	direction[2] = {0, 1};
	direction[3] = {0, -1};

	visited = vector< vector<int> >(n, vector<int>(m, 0));
	bfs();

	cout << visited[n - 1][m - 1] << "\n";

	return 0;
}

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int MAX = 100000000;

int main()
{
	int n, m, a, b, c;
	cin >> n >> m;

	vector< vector<int> > dist(n + 1, vector<int>(n + 1, MAX));
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == MAX)
				cout << "0 ";
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

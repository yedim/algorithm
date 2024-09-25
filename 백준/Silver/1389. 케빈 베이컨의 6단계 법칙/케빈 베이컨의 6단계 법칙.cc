#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, a, b;
	cin >> n >> m;

	vector< vector<int> > v(n + 1, vector<int>(n + 1, 10000000));
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1;
	}
	for (int i = 1; i <= n; i++)
		v[i][i] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
	
	vector<int> bacon(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			bacon[i] += v[i][j];
	}

	cout << min_element(bacon.begin() + 1, bacon.end()) - bacon.begin() << "\n";

	return 0;
}

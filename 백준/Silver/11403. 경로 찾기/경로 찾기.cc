#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, tmp;
	cin >> n;

	vector< vector<int> > v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][k] == 1 && v[k][j] == 1)
					v[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << v[i][j] << " ";
		cout << "\n";
	}

	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp;
	cin >> n;

	vector<int> v(10001, 0);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v[tmp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < v[i] && 0 < v[i]; j++)
			cout << i << "\n";
	}
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;
		cout << binary_search(a.begin(), a.end(), target) << "\n";
	}
	return 0;
}

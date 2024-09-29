#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	
	set<string> set;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		set.insert(s);
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (set.find(s) != set.end())
			cnt++;
	}

	cout << cnt << "\n";

	return 0;
}

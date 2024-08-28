#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int Find(int num)
{
	if (num == v[num])
		return num;
	else
		return v[num] = Find(v[num]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
		v[i] = i;

	for (int i = 0; i < m; i++) {
		int k, a, b;
		cin >> k >> a >> b;
		if (k == 0)
			v[Find(b)] = Find(a);
		else if (k == 1) {
			if (Find(a) == Find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}

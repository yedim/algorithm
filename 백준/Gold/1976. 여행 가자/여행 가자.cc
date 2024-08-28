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
	int n, m, tmp;
	cin >> n >> m;

	v.resize(n + 1);
	for (int i = 0; i <= n; i++)
		v[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tmp;
			if (tmp == 1 && i <= j)
				v[Find(j)] = Find(i);
		}
	}

	cin >> tmp;
	int chk = Find(tmp);
	for (int i = 0; i < m - 1; i++) {
		cin >> tmp;
		if (chk != Find(tmp)) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";

	return 0;
}

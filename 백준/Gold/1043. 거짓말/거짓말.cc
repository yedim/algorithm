#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int find(int num)
{
	if (num == v[num])
		return num;
	else
		return v[num] = find(v[num]);
}

int main()
{
	int n, m, k, num, tmp;
	cin >> n >> m;

	v.resize(n + 1);
	for (int i = 0; i <= n; i++)
		v[i] = i;

	cin >> k;
	vector<int> jinsil(k);
	for (int i = 0; i < k; i++)
		cin >> jinsil[i];

	vector<int> party(m);
	for (int i = 0; i < m; i++) {
		cin >> num >> party[i];
		for (int j = 0; j < num - 1; j++) {
			cin >> tmp;
			v[find(tmp)] = find(party[i]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		bool chk = true;
		for (int j = 0; j < k; j++) {
			if (find(party[i]) == find(jinsil[j]))
				chk = false;
		}
		if (chk) cnt++;
	}

	cout << cnt << "\n";

	return 0;
}

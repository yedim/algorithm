#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<int> parent;

int find(int n)
{
	if (n == parent[n])
		return n;
	else
		return parent[n] = find(parent[n]);
}

int main()
{
	int n, len;
	cin >> n;

	char c;
	string s;
	int result = 0;
	priority_queue< tuple<int, int, int>, vector< tuple<int, int, int> >, greater< tuple<int, int, int> > > pq;
	parent.resize(n);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] != '0') {
				if ('a' <= s[j] && 'z' >= s[j])
					len = s[j] - 'a' + 1;
				else
					len = s[j] - 'A' + 27;

				result += len;
				if (i != j)
					pq.push({len, i, j});
			}
		}
	}

	int cnt = 0;
	while (!pq.empty()) {
		tuple<int, int, int> curr = pq.top();
		pq.pop();

		int s = find(get<1>(curr));
		int e = find(get<2>(curr));
		if (s != e) {
			parent[e] = s;
			cnt++;
			result -= get<0>(curr);
		}
	}

	if (cnt == n - 1)
		cout << result << "\n";
	else
		cout << "-1\n";

	return 0;
}

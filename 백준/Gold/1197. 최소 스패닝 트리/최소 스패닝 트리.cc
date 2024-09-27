#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<int> node;

int findNode(int n)
{
	if (node[n] == n)
		return n;
	else
		return node[n] = findNode(node[n]);
}

int main()
{
	int v, e, a, b, c;
	cin >> v >> e;

	priority_queue< tuple<int, int, int>, vector< tuple<int, int, int> >, greater< tuple<int, int, int> > > q;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		q.push({c, a, b});
	}

	node.resize(v + 1);
	for (int i = 0; i <= v; i++)
		node[i] = i;

	int cnt = 0;
	int sum = 0;
	while (cnt < v - 1) {
		tuple<int, int, int> t = q.top();
		q.pop();

		int n1 = findNode(get<1>(t));
		int n2 = findNode(get<2>(t));
		if (n1 != n2) {
			node[n2] = n1;
			cnt++;
			sum += get<0>(t);
		}
	}

	cout << sum << "\n";

	return 0;
}

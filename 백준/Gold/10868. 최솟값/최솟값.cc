#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

vector<long> tree;

long findMin(long s, long e)
{
	long val = LONG_MAX;
	while (s <= e) {
		if (s % 2 == 1)
			val = min(val, tree[s++]);
		if (e % 2 == 0)
			val = min(val, tree[e--]);
		s /= 2;
		e /= 2;
	}
	return val;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long n, m;
	cin >> n >> m;
	
	long size = 0, tmp = n;
	while (tmp != 0) {
		size++;
		tmp /= 2;
	}
	size = pow(2, size + 1);
	tree = vector<long>(size, LONG_MAX);

	long start = size / 2 - 1;
	for (long i = start + 1; i <= start + n; i++)
		cin >> tree[i];

	long i = size;
	while (--i != 0)
		tree[i / 2] = min(tree[i], tree[i / 2]);

	for (long i = 0; i < m; i++) {
		long a, b;
		cin >> a >> b;
		cout << findMin(start + a, start + b) << "\n";
	}

	return 0;
}

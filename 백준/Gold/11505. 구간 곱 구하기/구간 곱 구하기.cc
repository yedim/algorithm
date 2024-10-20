#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long MOD = 1000000007;
vector<long long> tree;

void change(long long idx, long long val)
{
	tree[idx] = val;
	while (idx > 1) {
		idx /= 2;
		tree[idx] = tree[idx * 2] % MOD * tree[idx * 2 + 1] % MOD;
	}
}

void print(long long s, long long e)
{
	long long mul = 1;
	while (s <= e) {
		if (s % 2 == 1)
			mul = mul * tree[s++] % MOD;
		if (e % 2 == 0)
			mul = mul * tree[e--] % MOD;
		s /= 2;
		e /= 2;
	}
	cout << mul % MOD << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m, k;
	cin >> n >> m >> k;

	long long size = 0, tmp = n;
	while (tmp != 0) {
		size++;
		tmp /= 2;
	}
	size = pow(2, size + 1);
	tree.resize(size, 1);

	long long start = size / 2 - 1;
	for (long long i = start + 1; i <= start + n; i++)
		cin >> tree[i];

	long long i = size;
	while (--i != 1)
		tree[i / 2] = tree[i / 2] * tree[i] % MOD;

	for (long long i = 0; i < m + k; i++) {
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
			change(start + b, c);
		else if (a == 2)
			print(start + b, start + c);
	}

	return 0;
}

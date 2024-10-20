#include <iostream>
#include <vector>                                                                              
#include <cmath>
using namespace std;

vector<long> tree;

void change(long idx, long val)
{
	long diff = val - tree[idx];
	while (idx > 0) {
		tree[idx] = tree[idx] + diff;
		idx /= 2;
	}
}

void print(long s, long e)
{
	long sum = 0;
	while (s <= e) {
		if (s % 2 == 1)
			sum += tree[s++];
		if (e % 2 == 0)
			sum += tree[e--];
		s /= 2;
		e /= 2;
	}
	cout << sum << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long n, m, k;
	cin >> n >> m >> k;
	
	// 배열 size 구하기: 2^k >= n의 최솟값 k 구한 후, 2^k * 2를 배열 size로 정의
	long size = 0, tmp = n;
	while (tmp != 0) {
		tmp /= 2;
		size++;
	}
	size = int(pow(2, size + 1)); // pow(base, n) : base^n
	tree.resize(size);
	
	// 원본 데이터 채우기, start index: 2^k
	long start = size / 2 - 1;
	for (long i = start + 1; i <= start + n; i++)
		cin >> tree[i];

	// 나머지 데이터 채우기 (자식 노드의 합)
	long i = size;
	while (--i != 1)
		tree[i / 2] += tree[i];

	for (long i = 0; i < m + k; i++) {
		long a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
			change(start + b, c);
		else if (a == 2)
			print(start + b, start + c);
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long min, max;
	cin >> min >> max;

	long long size = max - min + 1;
	vector<bool> v(size);
	for (long long i = 2; i <= sqrt(max); i++) {
		long long val = i * i;
		long long start = min / val;
		if (min % val != 0) start++;

		for (long long j = start; val * j <= max; j++) {
			v[(val * j) - min] = true;
		}
	}

	int cnt = 0;
	for (long long i = 0; i < size; i++)
		if (!v[i]) cnt++;

	cout << cnt << "\n";

	return 0;
}

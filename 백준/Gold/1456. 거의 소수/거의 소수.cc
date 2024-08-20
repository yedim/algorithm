#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	long long a, b;
	cin >> a >> b;

	vector<bool> v(10000001, true);
	v[1] = false;
	for (long long i = 2; i <= 10000000; i++) {
		for (long long j = i + i; j <= 10000000; j += i)
			v[j] = false;
	}

	int cnt = 0;
	for (long long i = 2; i <= 10000000; i++) {
		if (v[i]) {
			for (long long j = i; (double)i <= (double)b / (double)j; j *= i) {
				if ((double)i >= (double)a / (double)j)
					cnt++;
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}

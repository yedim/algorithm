#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

bool isPalin(int i)
{
	string str = to_string(i);
	for (int s = 0, e = str.length() - 1; s <= e; s++, e--) {
		if (str[s] != str[e])
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;

	vector<bool> v(10000001, true);
	v[1] = false;
	for (int i = 2; i <= 10000000; i++) {
		for (int j = i + i; j <= 10000000; j += i) {
			v[j] = false;
		}
	}

	for (int i = n; i <= 10000000; i++) {
		if (v[i]) {
			if (isPalin(i)) {
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long n;
	cin >> n;
	long result = n;

	for (long i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			result = result - result / i;
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1)
		result = result - result / n;

	cout << result << "\n";

	return 0;
}

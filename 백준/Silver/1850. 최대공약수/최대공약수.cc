#include <iostream>
using namespace std;

long long gcb(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return gcb(b, a % b);
}

int main()
{
	long long a, b;
	cin >> a >> b;

	long long ret = gcb(a, b);
	for (long long i = 0; i < ret; i++)
		cout << "1";
	cout << "\n";

	return 0;
}

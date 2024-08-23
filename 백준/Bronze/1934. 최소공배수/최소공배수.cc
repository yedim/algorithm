#include <iostream>
using namespace std;

int gcb(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcb(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, a, b;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << a * b / gcb(a, b) << "\n";
	}

	return 0;
}

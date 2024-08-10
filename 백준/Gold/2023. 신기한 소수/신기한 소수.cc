#include <iostream>
using namespace std;

int n;

bool isPrime(int num)
{
	for (int i = 2; i < num / 2; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void dfs(int num, int jarisu)
{
	if (n == jarisu) {
		if (isPrime(num))
			cout << num << "\n";
		return;
	}

	for (int i = 1; i < 10; i+=2) {
		int tmp = num * 10 + i;
		if (isPrime(tmp))
			dfs(tmp, jarisu + 1);
	}
}

int main()
{
	cin >> n;

	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);

	return 0;
}

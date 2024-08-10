#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> num(n, 0);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	
	sort(num.begin(), num.end());

	int i = 0, j = n - 1, result = 0, sum;
	while (i < j) {
		sum = num[i] + num[j];
		if (sum == m)
			result++;
		if (sum <= m)
			i++;
		if (sum >= m)
			j--;
	}

	cout << result << "\n";

	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	long n, m;
	cin >> n >> m;
	long num_arr[n], sum_arr[n], ans_arr[m];
	
	for (int i = 0; i < n; i++) {
		cin >> num_arr[i];
		if (i == 0)
			sum_arr[i] = num_arr[i];
		else
			sum_arr[i] = sum_arr[i - 1] + num_arr[i];
	}
	
	long a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a -= 1; b -= 1;
		ans_arr[i] = sum_arr[b];
		if (a != 0)
			ans_arr[i] -= sum_arr[a - 1];
	}

	for (int i = 0; i < m; i++) {
		cout << ans_arr[i] << '\n';
	}
}

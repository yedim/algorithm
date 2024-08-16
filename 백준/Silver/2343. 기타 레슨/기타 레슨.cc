#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int start = 0, end = 0; // start: 총합계, end: 가장 큰 값
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		end += v[i];
		if (start < v[i])
			start = v[i];
	}
	
	while (start <= end) {
		int mid = (end + start) / 2;
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (sum + v[i] > mid) {
				cnt++;
				sum = 0;
			}
			sum += v[i];
		}
		if (sum > 0)
			cnt++;
		if (cnt <= m)
			end = mid - 1;
		else
			start = mid + 1;
	}

	cout << start << "\n";

	return 0;
}

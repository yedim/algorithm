#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int zero = 0, one = 0, tmp;
	priority_queue<int> positive;
	priority_queue< int, vector<int>, greater<int> > negative;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == 0)
			zero++;
		else if (tmp == 1)
			one++;
		else if (tmp > 1)
			positive.push(tmp);
		else
			negative.push(tmp);
	}

	int sum = 0;
	// 양수 묶기, 나머지 더하기
	// 음수 묶기, 나머지 0 있음 곱하기. 아님말고
	// 1 더하기
	while (!positive.empty()) {
		int a = positive.top();
		positive.pop();
		if (positive.empty()) {
			sum += a;
			break;
		}
		int b = positive.top();
		positive.pop();

		sum += a * b;
	}

	while (!negative.empty()) {
		int a = negative.top();
		negative.pop();
		if (negative.empty()) {
			if (zero == 0)
				sum += a;
			break;
		}
		int b = negative.top();
		negative.pop();

		sum += a * b;
	}

	sum += one;

	cout << sum << "\n";

	return 0;
}

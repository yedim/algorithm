#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue< int, vector<int>, greater<int> > pq;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	int sum = 0;
	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		pq.push(a + b);
		sum += a + b;
	}

	cout << sum << "\n";

	return 0;
}

#include <iostream>
#include <queue>
using namespace std;

struct cmp {
	bool operator() (int lhs, int rhs) {
		if (abs(lhs) == abs(rhs))
			return lhs > rhs;
		else
			return abs(lhs) > abs(rhs);
	}
};

int main()
{
	int n, x;
	cin >> n;

	priority_queue<int, vector<int>, cmp> pq;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (pq.empty())
				cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		} else
			pq.push(x);
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cin.tie(NULL);
	
	int n, l;
	cin >> n >> l;

	vector<int> num(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	deque< pair<int, int> > dq; // index, num
	for (int i = 0; i < n; i++) {
		while (dq.size() > 0 && dq.back().second >= num[i])
			dq.pop_back();
		dq.push_back(pair<int, int>(i, num[i]));
		if (dq.front().first <= i - l)
			dq.pop_front();
		cout << dq.front().second << " ";
	}
	cout << "\n";

	return 0;
}

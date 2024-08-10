#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	stack<int> s;
	vector<int> result(n, -1);
	s.push(0);
	for (int i = 1; i < n; i++) {
		while (!s.empty() && v[i] > v[s.top()]) {
			result[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < n; i++)
		cout << result[i] << " ";
	cout << "\n";

	return 0;
}
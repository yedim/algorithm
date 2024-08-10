#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;

	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int num = 1;
	stack<int> s;
	vector<char> result;
	for (int i = 0; i < n; i++) {
		if (num <= v[i]) {
			while (num <= v[i]) {
				s.push(num);
				result.push_back('+');
				num++;
			}
			s.pop();
			result.push_back('-');
		} else {
			if (s.top() > v[i]) {
				cout << "NO\n";
				return 0;
			} else {
				s.pop();
				result.push_back('-');
			}
		}
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << '\n';

	return 0;
}
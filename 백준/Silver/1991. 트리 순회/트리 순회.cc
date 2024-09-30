#include <iostream>
#include <vector>
using namespace std;

vector< pair<int, int> > v;

void preOrder(int n)
{
	if (n != -1) {
		cout << (char)(n + 'A');
		preOrder(v[n].first);
		preOrder(v[n].second);
	}
}

void inOrder(int n)
{
	if (n != -1) {
		inOrder(v[n].first);
		cout << (char)(n + 'A');
		inOrder(v[n].second);
	}
}

void postOrder(int n)
{
	if (n != -1) {
		postOrder(v[n].first);
		postOrder(v[n].second);
		cout << (char)(n + 'A');
	}
}

int main()
{
	int n;
	char m, l, r;
	cin >> n;

	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> m >> l >> r;
		v[m - 'A'].first = (l != '.') ? l - 'A' : -1;
		v[m - 'A'].second = (r != '.') ? r - 'A' : -1;
	}

	preOrder(0);
	cout << "\n";
	inOrder(0);
	cout << "\n";
	postOrder(0);
	cout << "\n";

	return 0;
}

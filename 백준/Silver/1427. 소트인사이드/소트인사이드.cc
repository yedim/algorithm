#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n.length(); i++)
		v.push_back(stoi(n.substr(i, 1)));

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	cout << "\n";

	return 0;
}

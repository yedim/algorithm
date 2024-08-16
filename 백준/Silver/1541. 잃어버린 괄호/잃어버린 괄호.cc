#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> split(string s, char d)
{
	stringstream ss(s);
	string tmp;
	vector<string> ret;

	while (getline(ss, tmp, d))
		ret.push_back(tmp);

	return ret;
}

int main()
{
	string str;
	cin >> str;

	int result = 0;
	vector<string> v = split(str, '-');
	for (int i = 0; i < v.size(); i++) {
		int sum = 0;
		vector<string> tmp = split(v[i], '+');
		for (int j = 0; j < tmp.size(); j++) {
			sum += stoi(tmp[j]);
		}
		if (i == 0)
			result += sum;
		else
			result -= sum;
	}

	cout << result << "\n";

	return 0;
}

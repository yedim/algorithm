#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector< vector< tuple<long long, long long, long long> > > arr;
vector<long long> result;

long long gcb(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return gcb(b, a % b);
}

void dfs(long long i)
{
	for (long long k = 0; k < arr[i].size(); k++) {
		tuple<long long, long long, long long> t = arr[i][k];
		long long next = get<0>(t);
		if (!result[next]) {
			result[next] = result[i] * get<2>(t) / get<1>(t);
			dfs(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, a, b, p, q, lcm = 1;
	cin >> n;

	arr.resize(n);
	for (long long i = 0; i < n - 1; i++) {
		cin >> a >> b >> p >> q;
		arr[a].push_back(make_tuple(b, p, q));
		arr[b].push_back(make_tuple(a, q, p));
		lcm *= (p * q) / gcb(p, q);
	}

	result = vector<long long>(n, 0);
	result[0] = lcm;
	dfs(0);

	long long g = result[0];
	for (long long i = 1; i < n; i++)
		g = gcb(g, result[i]);
	for (long long i = 0; i < n; i++)
		cout << result[i] / g << " ";
	cout << "\n";

	return 0;
}

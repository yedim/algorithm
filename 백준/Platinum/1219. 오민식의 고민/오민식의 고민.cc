#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
using namespace std;

int main()
{
	int n, start, end, m, a, b, c;
	cin >> n >> start >> end >> m;

	vector< tuple<int, int, int> > v;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v.push_back({a, b, c});
	}

	vector< pair<long, long> > dist(n); // 총액(dist), 해당 도시 수익
	for (int i = 0; i < n; i++) {
		dist[i].first = LONG_MIN;
		cin >> dist[i].second;
	}

	dist[start].first = dist[start].second;
	for (int i = 0; i < n + 50; i++) {
		for (tuple<int, int, int> tmp : v) {
			int s = get<0>(tmp);
			int e = get<1>(tmp);
			int cost = get<2>(tmp);
			if (dist[s].first == LONG_MAX)
				dist[e].first = LONG_MAX;
			else if (dist[s].first != LONG_MIN && dist[e].first < dist[s].first + dist[e].second - cost) {
				dist[e].first = dist[s].first + dist[e].second - cost;
				if (i > n)
					dist[e].first = LONG_MAX;
			}
		}
	}

	if (dist[end].first == LONG_MIN)
		cout << "gg\n";
	else if (dist[end].first == LONG_MAX)
		cout << "Gee\n";
	else
		cout << dist[end].first << "\n";

	return 0;
}

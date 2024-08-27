#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int a, b, c;
queue< tuple<int, int, int> > q;
bool visited[201][201][201];
vector<int> result;

void checkVisited(int next_a, int next_b, int next_c)
{
	if (!visited[next_a][next_b][next_c]) {
		visited[next_a][next_b][next_c] = true;
		q.push(make_tuple(next_a, next_b, next_c));
		if (next_a == 0) {
			result.push_back(next_c);
		}
	}
}

void bfs()
{
	q.push(make_tuple(0, 0, c));
	visited[0][0][c] = true;
	result.push_back(c);

	while (!q.empty()) {
		tuple<int, int, int> front = q.front();
		q.pop();
		int curr_a = get<0>(front);
		int curr_b = get<1>(front);
		int curr_c = get<2>(front);

		// a -> b
		checkVisited(max(curr_a + curr_b - b, 0), min(curr_a + curr_b, b), curr_c);
		// a -> c
		checkVisited(max(curr_a + curr_c - c, 0), curr_b, min(curr_a + curr_c, c));
		// b -> a
		checkVisited(min(curr_a + curr_b, a), max(curr_b + curr_a - a, 0), curr_c);
		// b -> c
		checkVisited(curr_a, max(curr_b + curr_c - c, 0), min(curr_b + curr_c, c));
		// c -> a
		checkVisited(min(curr_a + curr_c, a), curr_b, max(curr_c + curr_a - a, 0));
		// c -> b
		checkVisited(curr_a, min(curr_b + curr_c, b), max(curr_c + curr_b - b, 0));
	}
}

int main()
{
	cin >> a >> b >> c;

	bfs();

	sort(result.begin(), result.end());
	for (int i : result)
		cout << i << " ";
	cout << "\n";

	return 0;
}

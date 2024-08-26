#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > arr;
vector<bool> visited;
vector<int> check;
bool isEven;

void dfs(int n)
{
	visited[n] = true;
	for (int i : arr[n]) {
		if (!visited[i]) {
			check[i] = (check[n] + 1) % 2;
			dfs(i);
		} else if (check[n] == check[i])
			isEven = false;
	}
}

int main()
{
	int k, v, e, a, b;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> v >> e;
		
		arr = vector< vector<int> >(v + 1);
		for (int j = 0; j < e; j++) {
			cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		isEven = true;
		visited = vector<bool>(v + 1, false);
		check = vector<int>(v + 1, 0);
		for (int j = 1; j <= v; j++) {
			if (!isEven) break;
			dfs(j);
		}

		if (isEven)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}

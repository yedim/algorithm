#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

void swap(vector<int>& v, int i, int j)
{
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

int partition(vector<int>& v, int i, int j)
{
	if (i + 1 == j) {
		if (v[i] > v[j])
			swap(v, i, j);
		return j;
	}
	int mid = (i + j) / 2;
	int pivot = i++;
	swap(v, pivot, mid);
	while (i <= j) {
		while (v[i] < v[pivot] && i < n) i++;
		while (v[pivot] < v[j] && j > 0) j--;
		if (i <= j)
			swap(v, i++, j--);
	}
	swap(v, pivot, j);
	return j;
}

void quickSelect(vector<int>& v, int i, int j)
{
	int pivot = partition(v, i, j);
	if (v[pivot] == k) return;
	else if (v[pivot] < k) quickSelect(v, pivot + 1, j);
	else quickSelect(v, i, pivot - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	// quickSelect(v, 0, n - 1);
	sort(v.begin(), v.end());
	cout << v[k - 1] << "\n";
}

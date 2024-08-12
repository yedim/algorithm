#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
vector<int> tmp;
long result = 0;

void mergeSort(int s, int e)
{
	if (e - s < 1) return;
	
	int m = s + (e - s) / 2;
	mergeSort(s, m);
	mergeSort(m + 1, e);

	for (int i = s; i <= e; i++)
		tmp[i] = v[i];
	
	int k = s;
	int i = s;
	int j = m + 1;
	while (i <= m && j <= e) {
		if (tmp[i] > tmp[j]) {
			result += j - k;
			v[k++] = tmp[j++];
		} else
			v[k++] = tmp[i++];
	}
	while (i <= m)
		v[k++] = tmp[i++];
	while (j <= e)
		v[k++] = tmp[j++];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	v.resize(n);
	tmp.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	mergeSort(0, n - 1);

	cout << result << "\n";

	return 0;
}

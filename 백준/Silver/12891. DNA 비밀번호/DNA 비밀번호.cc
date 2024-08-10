#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int s, p; // 문자열 길이, 부분 문자열 길이
	cin >> s >> p;

	string str;
	cin >> str;

	vector<int> chk(4, 0); // a, c, g, t 최소 개수
	for (int i = 0; i < 4; i++)
		cin >> chk[i];

	vector<int> curr(4, 0);
	for (int i = 0; i < p; i++) {
		if (str[i] == 'A')
			curr[0]++;
		else if (str[i] == 'C')
			curr[1]++;
		else if (str[i] == 'G')
			curr[2]++;
		else if (str[i] == 'T')
			curr[3]++;
	}

	int result = 0;
	int i = 0, j = i + p - 1;
	while (j < s) {
		int cnt = 0;
		for (int k = 0; k < 4; k++) {
			if (chk[k] <= curr[k])
				cnt++;
		}
		if (cnt == 4)
			result++;
		
		if (str[i] == 'A')
			curr[0]--;
		else if (str[i] == 'C')
			curr[1]--;
		else if (str[i] == 'G')
			curr[2]--;
		else if (str[i] == 'T')
			curr[3]--;
		i++;
		j++;
		if (str[j] == 'A')
			curr[0]++;
		else if (str[j] == 'C')
			curr[1]++;
		else if (str[j] == 'G')
			curr[2]++;
		else if (str[j] == 'T')
			curr[3]++;
	}

	cout << result << "\n";

	return 0;
}

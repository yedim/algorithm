#include <iostream>
using namespace std;

int main()
{
    int n, ans = 0;
    string num;
    cin >> n >> num;

    for (int i = 0; i < n; i++) {
        ans += num[i] - '0';
    }

    cout << ans << '\n';
}

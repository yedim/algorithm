#include <iostream>
using namespace std;

int main()
{
    double n, m = 0, tmp, avg = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (m < tmp)
            m = tmp;
        avg += tmp;
    }
    avg = avg / m * 100 / n;
    cout << avg << '\n';
}
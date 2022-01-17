#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y, n;
        cin >> x >> y >> n;
        int k = (n / x) * x + y;
        if (k > n)
            k -= x;
        cout << k << "\n";
    }
}
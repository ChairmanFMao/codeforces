#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << 0 << "\n";
            continue;
        } if ((a < b && a%2 != b%2) || (a > b && a%2 == b%2)) {
            cout << 1 << "\n";
            continue;
        } else
            cout << 2 << "\n";
    }
}
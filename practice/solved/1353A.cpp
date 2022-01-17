#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        if (n >= 3)
            n = 4;
        int out = n/2 * m;
        cout << out << "\n";
    }
}
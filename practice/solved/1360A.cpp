#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        int minimum = min(a, b);
        int side = max(minimum * 2, a+b-minimum);
        cout << side * side << "\n";
    }
}
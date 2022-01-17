#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        int diff = abs(a - b);
        int steps = ceil((double) diff / 10);
        cout << steps << endl;
    }
}
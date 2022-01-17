#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(void) {
    int k, n, w;
    cin >> k >> n >> w;
    int cost = 0;
    for (int i = 0 ; i < w; i++) {
        cost += (i + 1) * k;
    }
    int out = n - cost > 0 ? 0 : abs(n - cost);
    cout << out << endl;
}
#include <iostream>
#include <cmath>
using namespace std;

void solution() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int small = min(min(a,b),c);
    int big = max(max(a,b),c);
    int mid = a + b + c - small - big;
    string out = (big - small + big - mid <= n && (a + b + c + n) % 3 == 0) ? "YES" : "NO";
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solution();
}
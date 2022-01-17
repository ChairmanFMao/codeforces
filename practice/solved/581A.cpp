#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    int diff = min(a,b);
    int match = (a + b - 2 * min(a,b)) / 2;
    cout << diff << " " << match;
}
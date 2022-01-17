#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    int numbers[3];
    cin >> numbers[0] >> numbers[1] >> numbers[2];
    int parity = (numbers[0] % 2 == numbers[1] % 2 || numbers[0] % 2 == numbers[2] % 2) ? numbers[0] % 2 : numbers[1] % 2;
    int bad = 0;
    for (int i = 0; i < n; i++) {
        if (i >= 3) {
            int d;
            cin >> d;
            if (d % 2 != parity)
                bad = i+1;
        } else {
            if (numbers[i] % 2 != parity)
                bad = i+1;
        }
    }
    cout << bad << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}
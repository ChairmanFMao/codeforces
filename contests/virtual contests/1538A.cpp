#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> stones;
    for (int i = 0; i < n; i++) {
        int stone;
        cin >> stone;
        stones.push_back(stone);
    }
    int biggest = 0, smallest = n + 1, bi = 0, si = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] > biggest) {
            biggest = stones[i];
            bi = i;
        } if (stones[i] < smallest) {
            smallest = stones[i];
            si = i;
        }
    }
    // This took immense brain power(drew a diagram)
    int moves = 0;
    if (si > bi)
        swap(si, bi);
    moves = min(min(n - si, bi + 1), si + 1 + n - bi);
    cout << moves << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}
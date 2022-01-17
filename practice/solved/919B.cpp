#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Used brute force to get the answers, really bad algorithm nearly timed out

bool perfect(int a) {
    string b = to_string(a);
    int all = 0;
    for (int i = 0; i < b.length(); i++)
        all += b[i] - 48;
    return all == 10;
}

void solve() {
    int k;
    cin >> k;
    int good = 0, number = 0;
    while (good < k) {
        number++;
        if (perfect(number))
            good++;
    }
    cout << number << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
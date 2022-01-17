#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Somehow got WA on test 5 first try
// Need to accomodate if the odd digit is bigger or smaller than the even ones
// Need to swap it with the smallest, highest even number
// I just had to do some tweaking to check for smaller numbers ahead to my original algorithm

void solve() {
    string n;
    cin >> n;

    char last = n[n.size()-1];
    bool first = 1;
    int index = -1;
    for (int i = n.size()-1; i >= 0; i--) {
        if (!(n[i] & 1)) {
            if (first) {
                index = i;
                first = 0;
            } else if (n[i] < last)
                index = i;
        }
    }
    if (index != -1) {
        swap(n[index],n[n.size()-1]);
        cout << n << "\n";
    } else
        cout << -1 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
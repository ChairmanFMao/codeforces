
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 2e5;
vector<int> numbers(mxN);
int n;

// Ended up looking at the solution because I went down a bad rabbit hole

bool palindrome(int remove) {
    vector<int> testing;
    for (int i = 0; i < n; i++)
        if (numbers[i] != remove)
            testing.push_back(numbers[i]);
    for (int i = 0; i < (int) testing.size()/2; i++) {
        if (testing[i] != testing[testing.size()-1-i])
            return 0;
    }
    return 1;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    bool out = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] != numbers[n-1-i]) {
            out |= palindrome(numbers[i]);
            out |= palindrome(numbers[n-1-i]);
            break;
        }
    }

    out |= palindrome(0);
    cout << (out ? "YES" : "NO") << "\n";
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

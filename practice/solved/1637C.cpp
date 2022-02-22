
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Just need to find if there are enough evens to cover the odds
// Had to look at solution because contest was close, look for impossible cases

void solve() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int& i : numbers)
        cin >> i;
    
    if (*max_element(numbers.begin()+1,numbers.end()-1) == 1 || (n == 3 && numbers[1] % 2)) {
        cout << "-1\n";
        return;
    }

    ll out = 0;
    // The adding of one allows for the extra move odd ones get
    for (int i = 1; i < n-1; i++) {
        out += (numbers[i]+1) >> 1;
    }

    cout << out << "\n";
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

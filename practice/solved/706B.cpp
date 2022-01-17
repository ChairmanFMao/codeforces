#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Naive O(n^2) solution timed out on test 11
// Failed again due to dodgy binary search
// Failed again due to edge case
// Accepted fourth try! First of the 1100 grind!

vector<int> prices;
int binSearch(int a, int start, int end) {
    int midpoint = (start+end)/2;
    if (start == end)
        return start;
    if (a == prices[midpoint]) {
        while (a == prices[midpoint]) midpoint++;
        return midpoint;
    }
    else if (a > prices[midpoint])
        return binSearch(a, midpoint+1, end);
    else
        return binSearch(a, start, midpoint);
}

void solve() {
    int n;
    cin >> n;
    prices.clear();
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        prices.push_back(a);
    }
    sort(prices.begin(), prices.end());
    prices.push_back(1000000000);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        int out = binSearch(a, 0 , prices.size());
        if (out > n)
            out = n;
        cout << out << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Numbers of test cases are low and so is n, but O(2^n) is not viable
// I think that the strategy should be to maximize c
// Can only remove elements from start or end of array to create subsegment
const int mxN = 1e2;
int n, out;
vector<int> numbers(mxN);

void interval(int start, int end) {
    for (int i = start; i < end; i++)
        if (numbers[i] == 0)
            out++;
    out += end-start;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    out = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j+i <= n; j++) {
            interval(j,j+i);
        }
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

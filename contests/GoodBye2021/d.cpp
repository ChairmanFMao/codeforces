#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 50000;
int numbers[mxN];
ll sum[mxN+1];
bool selected[mxN];
int n, x;

bool check(int first, int second) {
    return sum[second] - sum[first] >= x * (second-first);
}

void solve() {
    cin >> n;
    ll total = 0;
    sum[0] = 0
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        total += numbers[i];
        sum[i+1] = total;
    }
    cin >> x;
    memset(selected, 0, sizeof selected);
    // t is very low for this question
    selected[0] = 1;
    // Potentially send the indexes to the function to be checked, move up the checking range from 2 to the max
    for (int i = 1; i < n-1; i++) {
        for (int j = 0; j < n-j; j++) {
            if (!check(j, j+i))
                selected[j+i] = 0;
            else
                i++;
        }
    }
    int out = 0;
    for (int i = 0; i < n; i++)
        out += selected[i];
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
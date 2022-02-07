
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& i : a)
        cin >> i;
    for (int& i : b)
        cin >> i;

    for (int i = 0; i < n; i++)
        if (a[i] > b[i])
            swap(a[i],b[i]);

    cout << *max_element(a.begin(),a.end()) * *max_element(b.begin(),b.end()) << "\n";
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

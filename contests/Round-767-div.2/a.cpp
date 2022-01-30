#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool compare(pair<int,int> one, pair<int,int> two) {
    return one.first < two.first;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> numbers(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i].first;
    for (int i = 0; i < n; i++)
        cin >> numbers[i].second;
    
    sort(numbers.begin(),numbers.end(),compare);
    int free = k;
    
    for (int i = 0; i < n; i++) {
        if (numbers[i].first <= free) {
            free += numbers[i].second;
            k += numbers[i].second;
        }
    }

    cout << k << "\n";
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



#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> numbers(n);
    for (int i = 0,a; i < n; i++) {
        cin >> a;
        numbers[i] = {a,i};
    }

    vector<int> smallest(n);
    int small = INT_MAX;
    for (int i = n-1; i >= 0; i--) {
        if (numbers[i].first < small)
            small = numbers[i].first;
        smallest[i] = small;
    }


    sort(numbers.begin(),numbers.end(),[](pair<int,int> a, pair<int,int> b) {return a.first > b.first;});
    
    int out = 0, current = INT_MAX, lowest = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (numbers[i].second < current && numbers[i].first < lowest) {
            current = numbers[i].second;
            lowest = smallest[numbers[i].second];
            out++;
        } else if (numbers[i].second < current) {
            current = numbers[i].second;
            lowest = smallest[numbers[i].second];
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

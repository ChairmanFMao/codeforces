
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int& i : numbers)
        cin >> i;
    
    int out = 0;
    for (int i = 0; i < n-2; i++) {
        if (numbers[i+1] > numbers[i] && numbers[i+1] > numbers[i+2]) {
            numbers[i+2] = max(numbers[i+1],i == n-3 ? 0 : numbers[i+3]);
            out++;
        } 
    }
    
    cout << out << "\n";
    for (int i : numbers)
        cout << i << " ";
    cout << "\n";
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

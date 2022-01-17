#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Looked at solution, just think about the logic of it all

void solve() {
    int n;
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    sort(numbers.begin(), numbers.end());
    // The sum of sides has to be more than twice the longest side
    for (int i = 0; i < n-2; i++) {
        if (numbers[i] + numbers[i+1] > numbers[i+2] && numbers[i] + numbers[i+2] > numbers[i+1] && numbers[i+1] + numbers[i+2] > numbers[i]) {
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}
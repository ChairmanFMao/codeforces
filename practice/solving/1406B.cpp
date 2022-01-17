#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first and second times due to runtime error on test 2
// Ended up looking at the solution and redesiging my code
// Ended up taking a break in the end as I couldn't really understand the sample solution

bool compare(ll one, ll two) {
    return abs(one) > abs(two);
}

void solve() {
    int n;
    cin >> n;
    vector<ll> numbers(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    sort(numbers.begin(), numbers.end(), compare);
    if (*max_element(numbers.begin(), numbers.end()) < 0) {
        cout << numbers[n-1] * numbers[n-2] * numbers[n-3] * numbers[n-4] * numbers[n-5] << "\n";
        return;
    }
    ll out = numbers[0] * numbers[1] * numbers[2] * numbers[3] * numbers[4];
    int ptr = n-1;
    if (numbers[0] * numbers[1] <= numbers[ptr] * numbers[ptr-1]) {
        out /= (numbers[3] * numbers[4]);
        out *= numbers[ptr] * numbers[ptr-1];
        if (numbers[0] * numbers[1] <= numbers[ptr-2] * numbers[ptr-3]) {
            out /= (numbers[0] * numbers[1]);
            out *= numbers[ptr-2] * numbers[ptr-3];
        }
    } else if (numbers[3] * numbers[4] < numbers[ptr] * numbers[ptr-1]) {
        out /= (numbers[3] * numbers[4]);
        out *= numbers[ptr] * numbers[ptr-1];
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
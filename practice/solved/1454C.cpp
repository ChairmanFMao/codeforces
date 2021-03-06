#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 2
// Decided to look at the tutorial because I was kinda stumped
// Accepted second try

void solve() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    vector<int> occurs(n+1,1);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    occurs[numbers[0]]--;
    occurs[numbers[n-1]]--;
    // Unique is function that returns a vector of numbers with no equal consecutive numbers, cool new function I didn't know about
    n = unique(numbers.begin(), numbers.end()) - numbers.begin();
    // Resize then makes numbers only the length of the unique numbers
    numbers.resize(n);
    for (int i : numbers)
        occurs[i]++;
    int lowest = 1e9;
    for (int i : numbers)
        lowest = min(occurs[i],lowest);
    cout << lowest << "\n";
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

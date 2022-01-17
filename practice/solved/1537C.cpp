#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 1
// Failed second try, WA test 2
// Looked at the solution because I wanted to, I was close but missed out on just using the sorted list instead of alternating from max to min
// Epicly accepted third try!

void solve() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    if (n == 2) {
        cout << min(numbers[0], numbers[1]) << " " << max(numbers[0],numbers[1]) << "\n";
        return;
    }
    sort(numbers, numbers+n);
    int difference = INT_MAX;
    pair<int,int> indexes = {-1,-1};
    for (int i = 0; i < n-1; i++) {
        if (numbers[i+1]-numbers[i] < difference) {
            difference = numbers[i+1]-numbers[i];
            indexes = {i,i+1};
        }
    }
    // I think the output needs to alternate between the biggest and smallest
    cout << numbers[indexes.first] << " ";
    for (int i = indexes.second+1; i < n; i++)
        cout << numbers[i] << " ";
    for (int i = 0; i < indexes.first; i++)
        cout << numbers[i] << " ";
    cout << numbers[indexes.second] << "\n";
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
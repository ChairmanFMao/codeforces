#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Looked at solution for this one, very close to finding the algorithm, kinda annoyed, kinda satisfied
// Accepted first try as looked at solution.

void solve() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    // Works by looping over the array backwards and allocating scores as sums of two other scores
    int score[n];
    for (int i = n-1; i >= 0; i--) {
        score[i] = numbers[i];
        int j = i + numbers[i];
        if (j < n) {
            score[i] += score[j];
        }
    }
    cout << *max_element(score, score + n) << "\n";
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
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    int smallest = numbers[0], si = 0;
    for (int i = 0; i < n; i++)
        if (numbers[i] < smallest) {
            si = i;
            smallest = numbers[i];
        }
    
    numbers[si] += si;
    int smallestMEX = *min_element(numbers);
    numbers[si] -= si;
    
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
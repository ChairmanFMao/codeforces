
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// (i + 1 < j) just a perculiar constraint
// Unsure of what method you would use to find j
// Probably something binary because of the number of questions constraint
// The overall number of violations is the sum of two triangle numbers
// Had to look at solution, makes use of binary search cleverly
// Looked at many other people's solutions trying to figure out a way to implement the
// solution outlined in the tutorial

void solve() {
    ll n, all, current = 0, other = 0;
    cin >> n;

    ll bottom = 2, top = n, mid = 0;
    // This binary search finds the last number that is reversed
    // We do this until the difference between them is 1 because we are just setting
    // them to mid rather than putting them slightly above and below
    while (top - bottom > 1) {
        mid = (bottom+top) >> 1;
        cout << "? " << mid << " " << n << endl;
        cin >> current;
        if (!current)
            top = mid;
        else
            bottom = mid;
    }
    
    // If we get the difference between top and top-1
    // it should be the number of swaps in the right hand side(between j and k)
    ll count1, count2;
    cout << "? 1 " << top << endl;
    cin >> count2;
    cout << "? 1 " << top-1 << endl;
    cin >> count1;
    ll j = top - (count2 - count1);
    
    // If we get the difference between j-1 and j-2
    // it should be the number of swaps in the left hand side(between i and j)
    cout << "? 1 " << j-1 << endl;
    cin >> count2;
    cout << "? 1 " << j-2 << endl;
    cin >> count1;
    ll i = j - 1 - (count2 - count1);

    cout << "! " << i << " " << j << " " << top << endl;
}

int main(void) {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}

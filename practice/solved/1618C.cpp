
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Had to look at solution because I spent quite a while thinking and couldn't get it

void solve() {
    ll n;
    cin >> n;
    vector<ll> numbers(n);
    for (int i = 0; i <n ; i++)
        cin >> numbers[i];
    
    // Brute force wouldn't be possible
    ll evenGCD = numbers[0], oddGCD = numbers[1];
    for (int i = 2; i < n; i+=2)
        evenGCD = __gcd(evenGCD,numbers[i]);
    for (int i = 3; i < n; i+=2)
        oddGCD = __gcd(oddGCD,numbers[i]);
    
    bool even = 1, odd = 1;
    for (int i = 1; i < n; i+=2)
        if (numbers[i] % evenGCD == 0)
            even = 0;
    for (int i = 0; i < n; i+=2)
        if (numbers[i] % oddGCD == 0)
            odd = 0;
    
    if (even)
        cout << evenGCD;
    else if (odd)
        cout << oddGCD;
    else
        cout << 0;
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

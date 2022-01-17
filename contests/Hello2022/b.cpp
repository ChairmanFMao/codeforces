#include <bits/stdc++.h>
using namespace std;
#define ll long long

// WA on pretest 2 first try
// Still WA on pretest 2 after some more debugging
// Even with smallpot and bigpot still WA test 2
// I thought I was having integer overflow but, it wasn't that
// Trying to think of an edge case that the algorithm wouldn't catch
// TLE on test 3
// Just had to fix the smallpot and bigpot as just pairs, not pairs of vectors

void solve() {
    ll n;
    cin >> n;
    ll smallest = 1e9, biggest = 0, scost = 0, bcost = 0, spair = 0, bpair = 0;
    // Stores the price and pair number of potential candidates
    pair<ll,ll> smallpot, bigpot;
    for (int i = 0; i < n; i++) {
        ll l, r, c;
        cin >> l >> r >> c;
        // Assign l and r if they are out of the current bounds
        if (l < smallest) {
            scost = c;
            smallest = l;
            spair = i;
            smallpot = {1e9+1,-1};
        }
        if (r > biggest) {
            bcost = c;
            biggest = r;
            bpair = i;
            bigpot = {1e9+1,-1};
        }
        // Assign l and r if the lower bound is equal to the upper
        if (l == smallest && bpair == i) {
            if (scost < smallpot.first)
                smallpot = {scost,spair};
            scost = c;
            spair = i;
        }
        if (r == biggest && spair == i) {
            if (bcost < bigpot.first)
                bigpot = {bcost,bpair};
            bcost = c;
            bpair = i;
        }
        // Assign l and r if it is just cheaper to do so
        if (l == smallest && bpair != spair && c < scost) {
            if (scost < smallpot.first)
                smallpot = {scost,spair};
            scost = c;
            spair = i;
        }
        if (r == biggest && bpair != spair && c < bcost) {
            if (bcost < bigpot.first)
                bigpot = {bcost,bpair};
            bcost = c;
            bpair = i;
        }
        // Override a double pair if it is cheaper
        if (r == biggest && l == smallest && bpair == spair && c < scost) {
            if (bcost < bigpot.first)
                bigpot = {bcost,bpair};
            if (scost < smallpot.first)
                smallpot = {scost,spair};
            bcost = c;
            scost = c;
            bpair = i;
            spair = i;
        }
        if (r == biggest && l == smallest && bpair != spair && c < scost + bcost) {
            if (bcost < bigpot.first)
                bigpot = {bcost,bpair};
            if (scost < smallpot.first)
                smallpot = {scost,spair};
            bcost = c;
            scost = c;
            bpair = i;
            spair = i;
        }
        // This keeps a vector of potential segments
        if (r == biggest && c < bigpot.first)
            bigpot = {c,i};
        if (l == smallest && c < smallpot.first)
            smallpot = {c,i};
        
        // This evaluates the potential vectors to see if they are cheaper, if they are price is then reassigned
        if (smallpot.first + bigpot.first < (spair == bpair ? bcost : bcost + scost)) {
            bcost = bigpot.first;
            scost = smallpot.first;
            spair = smallpot.second;
            bpair = bigpot.second;
        }

        cout << (spair == bpair ? bcost : bcost + scost) << "\n";
    }
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
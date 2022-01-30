#include <bits/stdc++.h>
using namespace std;
#define ll long long

// I can think of a solution but it would take more than 10^6 operations every time.
const int mxN = 1e6;
vector<int> powers;
vector<int> dist(mxN+1);

int to(int a, int b) {
    vector<bool> bitsa, bitsb;
    for (int i = 0; i < (int) powers.size(); i++) {
        bitsa.push_back(powers[i] & a);
        bitsb.push_back(powers[i] & b);
    }
    bool first = 1;
    int total = 0;
    for (int i = (int)bitsa.size()-1; i >= 0; i--) {
        if (first && bitsb[i])
            total += powers[i];
        else if (first && bitsa[i] && !bitsb[i]) {
            total += powers[i];
            first = 0;
        } else if (!first && bitsa[i]) {
            total += powers[i];
        }
    }
    return total-b + 1;
}

void solve() {
    for (int i = 0; i <= mxN; i++)
        dist[i] = 1e9;

    int a, b;
    cin >> a >> b;
    int shortest = b-a;
    int nextpow = 0;
    for (int i = 0; i < (int) powers.size(); i++)
        if (powers[i] > b) {
            nextpow = powers[i];
            break;
        }
    
    // Need to somehow allow b to change during the process.
    shortest = min(nextpow-b, shortest);
    for (int i = a; i <= b; i++) {
        dist[i] = min(dist[i],i-a);
        shortest = min(shortest, b-i+dist[i]);
        shortest = min(shortest,to(i,b) + dist[i]);
        
        dist[i|b] = min(dist[i|b], dist[i]+1);
    }

    

    cout << shortest << "\n";
}
        
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 1; i < (int)3e6; i += i)
        powers.push_back(i);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}

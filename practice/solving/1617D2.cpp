
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Unsure how to optmise my technique from the first half of the problem
// I feel like you should be able to work out which people are imposters
// from just a single pass over the numbers but, I can't think of a way.

void solve() {
    int n;
    cin >> n;
    vector<bool> queries(n-2);
    // In this 0 signifies an imposter, 1 is a crewmate and -1 is undecided
    vector<bool> imposters(n, -1);
    cout << "? 1 2 3\n";
    bool flag = 1;
    cin >> queries[0];
    int ptr = 2;

    int imp = 0, crew = 0;

    while (ptr < n-1) {
        cout << "? " << ptr << " " << ptr+1 << " " << ptr+2 << "\n";
        cout.flush();
        cin >> queries[ptr-1];

        if (queries[ptr-1] != queries[0] && flag) {
            imposters[ptr-1] = queries[0];
            imposters[ptr+2] = !queries[0];
            
            flag = 0;
        }
        ptr++;
    }
}

int main(void) {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}

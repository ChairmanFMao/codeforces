#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Answer currently working for smaller numbers but not the bigger example, its about 5000 off
// Time limit exceeded on pretest 3, the time complexity is like O(nm) currently
// New solution got a WA on pretest 2, I think I will move on and come back to this later
// Unsure how to optimise the algorithm, or exactly where it went wrong
// WA on pretest 2 again, also getting bad wifi issues currently
// Some bug fixes done to algorithm but still got WA on pretest 2
// With optimisations to the original algorithm it still times out on test 3
// With fixes to the faster algorithm it still fails pretest 2

void solve() {
    int l, r;
    cin >> l >> r;
    
    
    if (r == l+1 && !(r & l)) {
        cout << 1 << "\n";
        return;
    }

    vector<int> powers;
    for (int i = 1; i <= r; i <<= 1) {
        if (l <= i && i <= r)
            powers.push_back(i);
    }
    int best = (r-l+1)/2;
    for (int i = 0; i < powers.size(); i++) {
        if (i == powers.size()-1) {
            best = min(best,powers[i] - l);
            continue;
        }
        best = min(best,r-l+1 - (powers[i+1] - powers[i]));
    }

    if (powers.size() == 0)
        best = 0;
    if (powers.size() == 1)
        best = min(best,min(r - powers[0], powers[0]-l)+1);

    cout << best << "\n";
    

    // I think that you need to look for the most common bit all share or smth
    // Need to find a fast way of finding the most common bit
    // This algorithm works whereas, the other one doesn't however, this one takes much longer to execute
    // map<int,int> mapping;
    // int high = 1;
    // for (int i = 0; i < 20; i++) {
    //     mapping[high] = 0;
    //     high <<= 1;
    // }
    // for (int i = l; i <= r; i++) {
    //     for (int j = 1; j <= i; j <<= 1) {
    //         if (i & j)
    //             mapping[j]++;
    //     }
    // }
    // int out = 0;
    // for (int i = 1; i <= high; i <<= 1)
    //     out = max(out, mapping[i]);
    
    // cout << r-l+1-out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}
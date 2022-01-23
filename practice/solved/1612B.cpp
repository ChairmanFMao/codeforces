
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<int> out(n);
    int ptr = 0;

    vector<bool> used(n+1, 0);
    out[ptr] = a;
    ptr++;
    used[a] = 1;
    int counter = 1;
    for (int i = n; i >= 0 && counter < n/2; i--) {
        if (i == b || used[i])
            continue;
        out[ptr] = i;
        ptr++;
        used[i] = 1;
        counter++;
    }
    
    out[ptr] = b;
    ptr++;
    used[b] = 1;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            out[ptr] = i;
            ptr++;
        }
    }
    
    if (*min_element(out.begin(),out.begin()+n/2) == a && *max_element(out.begin()+n/2,out.end()) == b) {
        for (int i : out) {
            cout << i << " ";
        }
    } else {
        cout << -1;
    }

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

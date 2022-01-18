
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<string> bi(n-2);
    for (int i=0;i<n-2;i++)
        cin >> bi[i];
    
    string out = "";
    bool extra = 0;
    for (int i = 0; i < (int)bi.size()-1;i++) {
        out += bi[i][0];
        if (bi[i][1] != bi[i+1][0]) {
            out += bi[i][1];
            extra = 1;
        }
    }
    out += bi[n-3][0];
    out += bi[n-3][1];
    if (!extra)
        out += 'a';
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}

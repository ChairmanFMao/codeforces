
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted second try(didn't read statement properly), with no help!
// Very happy that I managed to solve this myself!

void solve() {
    int n;
    cin >> n;
    cout << "? 1 2 3\n";
    bool prev, current;
    cin >> prev;
    int ptr = 2;

    int imp = 0, crew = 0;

    while (ptr < n-1) {
        cout << "? " << ptr << " " << ptr+1 << " " << ptr+2 << "\n";
        cout.flush();
        cin >> current;

        if (current != prev) {
            imp = prev ? ptr+2 : ptr-1;
            crew = prev ? ptr-1 : ptr+2;
            break;
        }
        ptr++;
    }

    vector<int> imposters;
    imposters.push_back(imp);
    for (int i = 1; i <= n; i++) {
        if (i == imp || i == crew)
            continue;

        cout << "? " << i << " " << imp << " " << crew << "\n";
        cout.flush();
        cin >> current;
        if (!current) {
            imposters.push_back(i);
        }
    }

    cout << "! " << imposters.size() << " ";
    for (int i : imposters)
        cout << i << " ";
    cout << "\n";
    cout.flush();
}

int main(void) {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}

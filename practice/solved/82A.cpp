#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Tried a simulation of doing this with queues for 1000000000, and it overflowed my RAM.
// Failed first try on test 9 for wrong answer
// Idk honestly, leave it for tomorrow in free period maybe. Gnite.

void solve() {
    long long n;
    cin >> n;
    vector<string> names;
    names.push_back("Sheldon");
    names.push_back("Leonard");
    names.push_back("Penny");
    names.push_back("Rajesh");
    names.push_back("Howard");
    for (long long i = 5; i <= n * 5; i*=3) {
        int counter = 0;
        for (long long j = i + i*(double)2/5; j < i*3; j+=i*(double)2/5) {
            if (n <= j) {
                cout << names[counter] << "\n";
                return;
            }
            counter++;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
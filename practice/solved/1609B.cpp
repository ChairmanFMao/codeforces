
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Complexity of O(qn) is too slow
// Just scraped past the test with like 10ms spare with current method

ll abcCount(string s) {
    ll out = 0;
    for (int i = 0; i < (int)s.size()-2; i++) {
        if (s.substr(i,3) == "abc")
            out++;
    }
    return out;
}

void solve() {
    int n, q, score;
    string s;
    cin >> n >> q >> s;
    score = abcCount(s);
    for (int i = 0; i < q; i++) {
        int index;
        char c;
        cin >> index >> c;
        index--;
        string temp = s;
        temp[index] = c;
        // Checks for the destruction and construction of ABC substrings
        if (index > 1 && index < n) {
            if (s.substr(index-2,3) == "abc" && temp.substr(index-2,3) != "abc")
                score--;
            if (s.substr(index-2,3) != "abc" && temp.substr(index-2,3) == "abc")
                score++;
        } if (index > 0 && index < n-1) {
            if (s.substr(index-1,3) == "abc" && temp.substr(index-1,3) != "abc")
                score--;
            if (s.substr(index-1,3) != "abc" && temp.substr(index-1,3) == "abc")
                score++;
        } if (index < n-2) {
            if (s.substr(index, 3) == "abc" && temp.substr(index, 3) != "abc")
                score--;
            if (s.substr(index,3) != "abc" && temp.substr(index,3) == "abc")
                score++;
        }

        s = temp;
        cout << score << "\n";
    }

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}

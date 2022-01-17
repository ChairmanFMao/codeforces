#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Had to look at the tutorial because I couldn't get code to work for test cases
// Accepted first try!

int checkSimilar(string testing, string toCompare) {
    // Turns out I should be interating over the testing one and then incrementing the toCompare pointer accordingly
    // If I had realised this the problem would've been easier
    int tp = 0, cp = 0, similarity = 0;
    while (tp < testing.size() && cp < toCompare.size()) {
        if (testing[tp] == toCompare[cp]) {
            similarity++;
            cp++;
        }
        tp++;
    }
    // Here is where I screwed up, we can't just return the similarity
    // We need to return the original length - similarity + toCompare length - similarity
    return testing.size() + toCompare.size() - similarity - similarity;
}

void solve() {
    string n;
    cin >> n;

    vector<string> powers;
    for (ll i = 1; i < (ll) 2e18; i <<= 1)
        powers.push_back(to_string(i));

    // Just seem to be getting one or two off on certain inputs currently, not sure why
    int mostSimilar = n.size() + 1;
    for (int i = 0; i < powers.size(); i++)
        mostSimilar = min(mostSimilar,checkSimilar(n,powers[i]));

    cout << mostSimilar << "\n";
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
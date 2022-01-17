#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Even though the algorithm is very bad, this got accepted first try

vector<int> primes = {2};

void solve() {
    int d;
    cin >> d;

    ll out[4];
    out[0] = 1;
    int index = 0;
    while (primes[index] - out[0] < d)
        index++;
    out[1] = primes[index];
    while (primes[index] - out[1] < d)
        index++;
    out[2] = primes[index];
    out[3] = out[1] * out[2];

    cout << out[3] << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testing = 3;
    bool prime;
    // 100000 is arbritary, for my purposes it was enough
    while (primes.size() < 100000) {
        prime = 1;
        for (int i = 3; i <= sqrt(testing); i+=2)
            if (testing % i == 0) {
                prime = 0;
                break;
            }
        
        if (prime)
            primes.push_back(testing);
        testing += 2;
    }

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}
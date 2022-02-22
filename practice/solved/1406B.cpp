
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Had to look at solution, was fumbling around with inefficient method

void solve() {
    int n;
    cin >> n;
    ll biggest = LLONG_MIN;
    vector<ll> numbers(n);
    for (ll& i : numbers) {
        cin >> i;
        biggest = max(i,biggest);
    }
    // Sorts all of the numbers by their absolute value
    sort(numbers.begin(),numbers.end(),[](ll x, ll y) {return abs(x) > abs(y);});
    // Takes care of the case where all of the numbers are negative.
    ll out = 1;
    if (biggest < 0) {
        for (int i = (int)numbers.size()-1; i > (int)numbers.size()-6; i--)
            out *= numbers[i];
        cout << out << "\n";
        return;
    }
    
    // This gets the product of the largest 5 numbers
    for (int i = 0; i < 5; i++)
        out *= numbers[i];
    // This iterates through the whole list and checks to see if any number
    // can be replaced to lead to a larger total.
    for (int i = 5; i < n; i++)
        for (int j = 0; j < 5; j++) {
            ll temp = numbers[i];
            for (int k = 0; k < 5; k++)
                if (k != j)
                    temp *= numbers[k];
            out = max(temp,out);
        }

    cout << out << "\n";

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

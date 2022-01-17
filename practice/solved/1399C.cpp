#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 2
// Failed second try, WA test 2, problem was actually due to there being 2 combinations of the most common sum
// Failed third try, WA test 2, index out of bounds
// Failed fourth try, WA test 2, just a random wrong answer
// Failed fifth try, WA test 2, just made a small change with no effect
// In the end looked at solution, you are just simply meant to brute force it
// Failed sixth try, WA test 1
// Finally, accepted on the seven try!
// Very interesting solution, a way of thinking that I wasn't even concieving

void solve() {
    int n;
    cin >> n;
    // We make an array with the occurences of each number as n is maximum 50 this is fine for space complexity
    int numbers[n+1];
    // Remember that the size of an integer is 4 bytes
    memset(numbers, 0, 4 * (n+1));
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers[a]++;
    }
    int out = 0;
    // Iterates over all of the possible sums
    for (int i = 2; i <= 2 * n; i++) {
        int current = 0;
        // Adds up all of the pairs that would create a sum of i
        for (int j = 1; j < (i+1)/2; j++) {
            if (i-j>n)
                continue;
            current += min(numbers[j], numbers[i-j]);
        }
        // If i is even then i/2 and i/2 would be a possible pair
        if ((i & 1) == 0)
            current += numbers[i/2] / 2;
        // Updating the output
        if (current > out)
            out = current;
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
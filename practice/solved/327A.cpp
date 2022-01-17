#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 4
// Failed second try, WA test 3, just an edge case that I am troubleshooting
// Failed third try, WA test 7
// Failed fourth try, WA test 8
// Failed fifth try, WA test 4
// Finally accepted sixth try, I didn't fully read the question until the fourth try failed, need to read with more detail.
// Also the algorithm is just brute force because the input can only be up to 100 numbers meaning that it would be efficient enough

void solve() {
    int n;
    cin >> n;
    int numbers[n], ones = 0;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        if (numbers[i])
            ones++;
    }
    
    if (n == 1 && numbers[0] == 0) {
        cout << 1 << "\n";
        return;
    }
    if (ones == n) {
        cout << n-1 << "\n";
        return;
    }
    int biggest = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int current = ones;
            for (int k = i; k <= j; k++) {
                if (numbers[k] == 0)
                    current++;
                else
                    current--;
            }
            if (current > biggest)
                biggest = current;
        }
    }
    cout << biggest << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
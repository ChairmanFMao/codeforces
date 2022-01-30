#include <bits/stdc++.h>
using namespace std;
#define ll long long

// got a WA on pretest 2 first try
// Even with big changes to the algorithm I got WA on pretest 2 again
// Another WA on pretest 2, not entirely sure what the problem is
// Still WA on pretest 2 after more bug fixes
// Removed some more unnecessary code but, I still end up with WA on test 2
// I think that the problem is that numbers are being used to make the wrong numbers, more versatile numbers are being used up for eaiser numbers
// I think that I somehow need it to check the smallest numbers first and then move upwards from there, the queue doesn't help because if a smaller
// Number doens't fit it gets pushed behind the biggest numbers, thinking about having a map to bools to see if the numbers have been used]
// I think this algorithm is also too slow tho, it's like O(n^2) ish I estimate, which won't work well for the 1e4 inputs of 1e5 length arrays
// I didn't manage to finish the problem during the contest, I might look at the solution after

void solve() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    sort(numbers,numbers+n);
    queue<int> q;
    for (int i = 0; i < n; i++)
        q.push(numbers[i]);
    int moves = 0;
    for (int i = 0; i < n; i++) {
        int current = q.front();
        q.pop();
        if (current == i+1)
            continue;
        if (current % (current-i-1) == i+1) {
            moves++;
            continue;
        }
        else {
            int size = q.size();
            q.push(current);
            bool flag = 0;
            for (int j = 0; j < size; j++) {
                int another = q.front();
                q.pop();
                if (another == i+1) {
                    flag = 1;
                    break;
                }
                if (another > (i+1)) {
                    if (another % (another-i-1) == i+1) {
                        moves++;
                        flag = 1;
                        break;
                    }
                }
                q.push(another);
            }
            if (flag)
                continue;
            cout << -1 << "\n";
            return;
        }
    }
    cout << moves << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}
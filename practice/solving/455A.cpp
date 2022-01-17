#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Two failed attempts on laptop, two on pc, I think I read question wrong, idk tho, after a fifth failure I looked at solution
// Followed solution but still timed out ;-;

map<int, int> numbers;
int betterSolve(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return numbers[1];
    else
        return max(betterSolve(n-1), betterSolve(n-2) + numbers[n] * n);
}

void solve() {
    int n;
    cin >> n;
    numbers.clear();
    numbers[1] = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers[a]++;
    }
    int score = betterSolve(n);
    cout << score << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace chrono;
#define ll long long

// I don't think that it would be wise to use a searching algorithm like dfs or bfs because I think that it would just lead to timeouts
// I think I may as well try it anyway tho
// Failed first try, WA test 5, I forgor to do the modulo and other errors, leading me to getting valid being too small
// Looked at the solution and I don't really understand it

// Turns out my solution was valid, the only thing was that it was limiting the tree to have a ceratin depth when it should actually be infinite
// However, this solution got TLE(time limit exceeded) on test 5 with its first submission
// With another bit of optimisation I submitted but, TLE on test 7
// I think that I need to redesign the whole algorithm if I want to be able to make it efficient enough to pass the test cases
// I am looking again at more solutions and trying to fully understand them, I will need to use one of them as my recurvise dfs doesn't scale well
// I think that I will finish it tomorrow after completing the aoc for that day, I am understanding more of the problem now, and some of the methods used to solve it
// You kinda build on the last move every time and stack up the numbers for the valid paths and invalid paths and you slowly sum the number of paths from the bottom
// of the k-tree upwards, the solutions I am looking at are very elegant and efficient.
// I am remaking the solution
// Very heavy help from solution but very satisfied in the end as I understand how the algorithm works

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    const ll mod = 1e9 + 7;

    ll numbers[n+1][2];
    numbers[0][0] = 1;
    numbers[0][1] = 0;

    for (int i = 1; i <= n; i++) {
        numbers[i][0] = numbers[i][1] = 0;

        for (int j = 1; j <= k; j++) {
            if (i - j < 0)
                break;
            if (j < d) {
                numbers[i][0] += numbers[i-j][0];
                numbers[i][0] %= mod;
                numbers[i][1] += numbers[i-j][1];
                numbers[i][1] %= mod;
            } else {
                numbers[i][1] += numbers[i-j][0] + numbers[i-j][1];
                numbers[i][1] %= mod;
            }
        }
    }
    cout << numbers[n][1] << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
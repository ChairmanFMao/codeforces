
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Tags say greedy and binary search, but I am not sure how a binary search could be implemented
// Thinking of sorting by max potential people and then binary searching, leads to O(n logn) I think
// Turns out my solution didn't work, I had to look at the editorial
// You just binary search to see if each value from 0 to n will work
// Actually very interesting solution

const int mxN = 2e5;
int n;
vector<pair<int,int>> people(mxN);

bool possible(int mid) {
    ll count = 0;
    for (int i = 0; i < n; i++) {
        // The first part of this line checks if it will work for all richer people, the second part validates for all poorer people
        if (mid-1-people[i].first <= count && count <= people[i].second)
            count++;
    }
    return count >= mid;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> people[i].first >> people[i].second;
    
    int lower = -1, upper = n+1, mid;
    while (upper - lower > 1) {
        mid = (lower + upper)/2;
        if (possible(mid)) {
            lower = mid;
        } else
            upper = mid;
    }

    cout << lower << "\n";
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

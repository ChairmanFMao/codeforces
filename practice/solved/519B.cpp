#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed on first try due to time out on test 17
// On second try managed to reduce algorithm to O(n) from O(2n), but used more count operators so timed out again on test 8
// Third try got accepted where I sorted the arrays first instead of using the count operator lots

void solve() {
    int n;
    cin >> n;
    int first[n], second[n-1], third[n-2];
    for (int i = 0; i < n; i++)
        cin >> first[i];
    for (int i = 0; i < n-1; i++)
        cin >> second[i];
    for (int i = 0; i < n-2; i++)
        cin >> third[i];
    vector<int> solved;
    sort(first, first+n);
    sort(third, third+n-2);
    int thirdptr = 0;
    for (int i = 0; i < n; i++) {
        if (first[i] != third[thirdptr])
            solved.push_back(first[i]);
        else
            thirdptr++;
    }
    if (count(second, second+n-1, solved[0]) > count(third, third+n-2, solved[0]))
        cout << solved[1] << "\n" << solved[0] << "\n";
    else
        cout << solved[0] << "\n" << solved[1] << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int& i : numbers)
        cin >> i;
    int ptr = 0;
    while (numbers[ptr] == ptr+1 && ptr < n)
        ptr++;

    if (ptr == n) {
        for (int i : numbers)
            cout << i << " ";
        cout << "\n";
        return;
    }
    int left = ptr, right = ptr;
    while (numbers[right] != ptr+1)
        right++;
    reverse(numbers.begin()+left,numbers.begin()+right+1);
    for (int i : numbers)
        cout << i << " ";
    cout << "\n";
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

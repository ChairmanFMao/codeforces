
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    int biggest = *max_element(numbers.begin(),numbers.end());
    if (biggest != numbers[0] && biggest != numbers[n-1]) {
        cout << "-1\n";
        return;
    }
    
    int nlptr = 0, nrptr = n-1;
    deque<int> out;
    
    int last = 0;
    for (int i = 0; i < n-1; i++) {
        if (numbers[nlptr] > numbers[nrptr]) {
            out.push_front(numbers[nlptr]);
            nlptr++;
            last = 0;
        } else {
            out.push_back(numbers[nrptr]);
            nrptr--;
            last = 1;
        }
    }
    if (last)
        out.push_front(numbers[nrptr]);
    else
        out.push_back(numbers[nrptr]);
    
    while (!out.empty()) {
        cout << out.front() << " ";
        out.pop_front();
    }
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

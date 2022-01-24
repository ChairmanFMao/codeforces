
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Took some time attempting but, ended up looking at the solution, you need to use a stack to keep the
// duplicates that you haven't used, I was thinking along these lines, but the stack enables the program
// to be much faster overall as you only need to do one pass over the array.

void solve() {
    int n;
    cin >> n;
    set<int> numbers;
    map<int,int> occurs;
    for (int i = 0,a; i < n; i++) {
        cin >> a;
        numbers.insert(a);
        occurs[a]++;
    }
    
    vector<int> unique(numbers.begin(),numbers.end());
    sort(unique.begin(),unique.end());
    vector<ll> out(n+1,-1);
    stack<int> st;
    ll total = 0;
    
    for (int i = 0; i <= n; i++) {
        if (i > 0 && occurs[i-1] == 0) {
            if (st.empty())
                break;
            int top = st.top();
            st.pop();
            total += i - top - 1;
        }
        out[i] = total + occurs[i];
        while (i > 0 && occurs[i-1] > 1) {
            occurs[i-1]--;
            st.push(i-1);
        }
    }

    for (ll i : out)
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

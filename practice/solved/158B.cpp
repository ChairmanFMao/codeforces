#include <bits/stdc++.h>
using namespace std;
#define ll long long

// First try :)

void solve() {
    int n;
    cin >> n;
    int one = 0, two = 0, three = 0, four = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1)
            one++;
        else if (a == 2)
            two++;
        else if (a == 3)
            three++;
        else if (a == 4)
            four++;
    }
    int cars = four;
    cars += two/2;
    two %= 2;
    cars += min(one, three);
    int temp = one;
    one -= min(one, three);
    three -= min(temp, three);
    if (three > 0)
        cars += three;
    cars += ceil((((double) two * 2) + one)/4);
    cout << cars << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}

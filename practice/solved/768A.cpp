#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try epicly

void solve() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    int max = *max_element(numbers, numbers+n), min = *min_element(numbers, numbers+n);
    int count = 0;
    for (int i = 0; i < n; i++)
        if (numbers[i] != max && numbers[i] != min)
            count++;
    cout << count << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
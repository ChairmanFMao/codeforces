#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Originally had a O(n^2) solution that I made myself
// Read tutorial and implemented an O(n)

int main(void) {
    int n;
    cin >> n;
    int out[n];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        out[a - 1] = i + 1;
    }
    string extra = " ";
    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            extra = "";
        cout << out[i] << extra;
    }
}
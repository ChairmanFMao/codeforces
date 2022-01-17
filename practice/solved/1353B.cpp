#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector<int> a, b;
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            a.push_back(input);
        }
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            b.push_back(input);
        }
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        int aptr = 0, bptr = 0;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (b[bptr] > a[aptr] && k > 0) {
                sum += b[bptr];
                bptr++;
                k--;
            } else {
                sum += a[aptr];
                aptr++;
            }
        }
        cout << sum << "\n";
    }
}
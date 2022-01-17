#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        set<int> numbers;
        int n;
        cin >> n;
        int min, max;
        cin >> min;
        max = min;
        numbers.insert(min);
        for (int j = 0; j < n - 1; j++) {
            int a;
            cin >> a;
            if (a > max)
                max = a;
            else if (a < min)
                min = a;
            numbers.insert(a);
        }
        bool bad = 0;
        for (int j = min; j <= max; j++) {
            if (numbers.count(j) == 0) {
                bad = 1;
                break;
            }
        }
        string out = bad ? "NO" : "YES";
        cout << out << endl;
    }
}
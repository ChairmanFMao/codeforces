
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 2*n - 2 queries to complete the problem, we are also allowed 2 guesses at the end
// If we find the values of 2 numbers then we can find the zero in n-2 queries
// Actually, we only the need the value of 1 number and another that is smaller than it
// I think that you need to look for the largest difference twice, just a hunch
// Worked first time! (after a silly compilation error)
// Actually very happy with my logic for this one.

void solve() {
    int n;
    cin >> n;

    int largest = 0;
    vector<int> indexes, other;
    // This gets the largest difference from two arbritary values
    for (int i = 3,r; i <= n; i++) {
        cout << "? 1 2 " << i << "\n";
        cout.flush();
        cin >> r;
        if (r > largest) {
            largest = r;
            indexes.clear();
            indexes.push_back(1);
            indexes.push_back(2);
            indexes.push_back(i);
        }
    }

    // This gets the largest difference from an extrema with an arbritary value
    largest = 0;
    for (int i = 2,r; i <= n; i++) {
        if (i == indexes[2])
            continue;
        cout << "? 1 " << indexes[2] << " " << i << "\n";
        cout.flush();
        cin >> r;
        if (r > largest) {
            largest = r;
            other.clear();
            other.push_back(1);
            other.push_back(indexes[2]);
            other.push_back(i);
        }
    }
    
    // Gets the first index that isn't important
    int first = 0;
    for (int i = 2; i <= n; i++) {
        if (i != other[1] && i != other[2]) {
            first = i;
            break;
        }
    }

    int r1 = 0, r2 = 0;
    cout << "? " << other[1] << " " << other[2] << " " << first << "\n";
    cout.flush();
    cin >> r1;
    cout << "? " << other[0] << " " << other[1] << " " << first << "\n";
    cout.flush();
    cin >> r2;
    
    if (r1 == largest)
        cout << "! " << other[1] << " " << other[2] << "\n";
    else if (r2 == largest)
        cout << "! " << other[0] << " " << other[1] << "\n";
    else
        cout << "! " << other[0] << " " << other[2] << "\n";
}

int main(void) {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}

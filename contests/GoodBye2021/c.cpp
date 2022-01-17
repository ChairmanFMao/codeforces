#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Potentially need to optimise later but, for now it passes the pretests, I think it's got O(n^4) lol

const int mxN = 70;
int numbers[mxN];
int n;

bool check(vector<double> temp) {
    vector<double> sums;
    sums.push_back(0);
    double sum = 0;
    for (int i = 0; i < temp.size(); i++) {
        sum += temp[i];
        sums.push_back(sum);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (abs((sums[j+1] - sums[i]) - ((temp[i]+temp[j])/2.0) * (j-i+1)) > 1e-9)
                return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    // Sum of subset needs to be equal to half of sum of bounds of subset times the difference of the indexes of the subset add one
    // I think that you just need to make the array a linear sequence
    // What if we just chose every pair of elements and used that difference to make the sequence then brute force it like that
    int best = n-1;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double increase = (numbers[j] - numbers[i]) / (double) (j-i);
            double start = numbers[j] - j * increase;
            int changes = 0;
            vector<double> temp(n);
            for (int k = 0; k < n; k++) {
                if (abs(numbers[k] - (start + increase*k)) > 1e-9)
                    changes++;
                temp[k] = start + increase*k;
            }
            if (check(temp))
                best = min(best, changes);
        }
    }
    cout << best << "\n";
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
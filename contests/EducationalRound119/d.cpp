#include <bits/stdc++.h>
using namespace std;
#define ll long long

// WA on test 2, first try, unsure of error
// Made some bug fixes and I am trying again, WA test 2 again, now totally unsure of error
// Fixed another bug that I noticed but, still no success
// After redesigning another bit, I still get the WA on test 2
// Every time I get WA on test 2

// Didn't manage to complete during the contest, I will look at the solution when the editorial is released

void solve() {
    int n;
    cin >> n;
    int numbers[n];
    bool modOne = 0, modTwo = 0, modThree = 0, literalone = 0, literaltwo = 0, allTwo = 1;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        if (numbers[i] % 3 == 1)
            modOne = 1;
        if (numbers[i] % 3 == 2)
            modTwo = 1;
        if (numbers[i] % 3 == 0)
            modThree = 1;
        if (numbers[i] == 1)
            literalone = 1;
        if (numbers[i] == 2)
            literaltwo = 1;
        if (numbers[i] & 1)
            allTwo = 0;
    }
    
    int one = 0, two = 0, three = 0;
    if (modOne && modTwo && modThree) {
        two++;
        one++;
    }
    if (modTwo && modOne && !modThree && allTwo)
        two += 2;
    if (modTwo && modOne && !modThree && !allTwo)
        one += 2;
    if (modOne && !modTwo)
        one++;
    if (modTwo && !modOne)
        two++;
    if (literalone && one == 0)
        one++;
    if (literaltwo && two == 0)
        two++;
    
    // Need to think about the extras that combinations of ones and twos can make up
    for (int i = 0; i < n; i++) {
        int currenttwo = two, currentone = one;
        if (numbers[i] % 3 == 2 && currenttwo > 0) {
            numbers[i] -= 2;
            currenttwo--;
        }
        else if (numbers[i] % 3 == 1 && currenttwo >= 2) {
            numbers[i] -= 4;
            currenttwo -= 2;
        }
        else if (numbers[i] % 3 == 1 && currentone >= 1) {
            numbers[i] -= 1;
            currentone--;
        }
        if (currenttwo >= 1 && currentone >= 1)
            numbers[i] -= 3;
        if (numbers[i] < 0)
            continue;
        three = max(three, numbers[i]/3);
    }
    cout << one+two+three << "\n";
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
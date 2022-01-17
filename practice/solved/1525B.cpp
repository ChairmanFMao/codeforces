#include <bits/stdc++.h>
using namespace std;

// I broke the 5 correct first try streak ;-;
// Solved on second submission, just tried the 6 combinations of sorting parts of the array and if they were equal to the sorted array
// to output the number of sorts performed to reach there.

void solve() {
    int n;
    cin >> n;
    vector<int> numbers, sorted, left, right, leftRight, rightLeft, leftRightLeft, rightLeftRight;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    sorted = numbers;
    sort(sorted.begin(), sorted.end());
    if (numbers == sorted) {
        cout << 0 << "\n";
        return;
    }
    left = right = numbers;
    sort(left.begin(), left.end() - 1);
    sort(right.begin() + 1, right.end());
    if (left == sorted || right == sorted) {
        cout << 1 << "\n";
        return;
    }
    leftRight = left;
    rightLeft = right;
    sort(leftRight.begin() + 1, leftRight.end());
    sort(rightLeft.begin(), rightLeft.end() - 1);
    if (leftRight == sorted || rightLeft == sorted) {
        cout << 2 << "\n";
        return;
    }
    leftRightLeft = leftRight;
    rightLeftRight = rightLeft;
    sort(leftRightLeft.begin(), leftRightLeft.end() - 1);
    sort(rightLeftRight.begin() + 1, rightLeftRight.end());
    if (leftRightLeft == sorted || leftRightLeft == sorted) {
        cout << 3 << "\n";
        return;
    }
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
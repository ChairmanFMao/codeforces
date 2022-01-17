#include <bits/stdc++.h>
using namespace std;
#define ll long long

// O(n^2) time is not an option as n can vary from 1 to 1e5
// I think the solution would involve checking for the number of decreasing subsequences in the array, just a thought tho
// Turns out this approach doesn't really work

vector<int> change(vector<int> numbers, int start, int end) {
    while (end - start > 1) {
        swap(numbers[start], numbers[end]);
        start++;
        end--;
    }
    return numbers;
}

bool equivalent(vector<int> first, vector<int> second) {
    for (int i = 0; i < first.size(); i++)
        if (first[i] != second[i])
            return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> numbers;
    vector<int> sortedNumbers;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers.push_back(a);
        sortedNumbers.push_back(a);
    }

    sort(sortedNumbers.begin(), sortedNumbers.end());
    
    int last = numbers[0], down = 0;
    bool decreasing = 0;
    int start = 0, end = 0;
    for (int i = 1; i < n; i++) {
        if (decreasing && last >= numbers[i])
            continue;
        else if (last > numbers[i]) {
            decreasing = 1;
            start = i-1;
            continue;
        } else {
            if (decreasing) {
                end = i-1;
                break;
            }
            decreasing = 0;
        }
        last = numbers[i];
    }
    if (decreasing)
        end = n-1;

    if (start != 0 && end != 0) {
        if (equivalent(change(numbers, start, end), sortedNumbers)) {
            cout << "YES" << "\n" << start << " " << end << "\n";
            return;
        }
    }
    cout << "NO" << "\n";

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
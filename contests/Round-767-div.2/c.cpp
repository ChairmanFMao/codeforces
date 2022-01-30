#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 2e5;
int n, current = 0;
vector<int> numbers(mxN),out;
map<int,int> occurs;

// Current strategy times out on test 2
// Need to store the indexes of all the numbers as well as their values

void MEX() {
    int number;
    for (int i = 0; i <= n; i++)
        if (occurs[i] == 0) {
            number = i;
            break;
        }
    
    int ptr = current;
    set<int> under;
    while ((int)under.size() < number && ptr < n) {
        occurs[numbers[ptr]]--;
        if (numbers[ptr] < number)
            under.insert(numbers[ptr]);
        ptr++;
    }
    
    if (number == 0)
        ptr++;
    out.push_back(number);
    current = ptr;
}

void solve() {
    for (int i = 0; i <= mxN; i++)
        occurs[i] = 0;
    out.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        occurs[numbers[i]]++;
    }

    // I can think of an O(n^2) solution but, I think that it will be too slow
    // I think that I need to make an array with values that are precalculated
    current = 0;
    while (current < n)
        MEX();
    
    cout << out.size() << "\n";
    for (int i : out)
        cout << i << " ";
    cout << "\n";
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

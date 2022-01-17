#include <bits/stdc++.h>
using namespace std;
#define ll long long

// timeout on test 5 first try, I think it is because of the very inefficient kinda O(n^2) algorithm
// Trying to think of a way of maintaining order of the operations
// Hard to think of a better way than just brute force lol
// I optimsed it by using an array but in the end it still led to timeout
// Went back to the map idea but, I got a WA on test 4
// With some minor changes, I still got a WA on test 4, the problem is with the numbers outputted not the order
// Troubleshooted even more bugs but still get the same WA on test 4
// I think that I am going to attempt to follow some idea that was put in the comments of the post, that I should process it in reverse order

// With this new approach I got it to be accepted on the first try, it did use a little more memory(28mb ish) but it was efficient

void solve() {
    int q;
    cin >> q;
    vector<vector<int>> numbers;
    int instruction, x, y;

    for (int i = 0; i < q; i++) {
        cin >> instruction >> x;
        if (instruction == 1)
            numbers.push_back({x});
        else {
            cin >> y;
            numbers.push_back({x,y});
        }
    }
    
    vector<int> out;
    map<int,int> mapping;
    for (int i = numbers.size()-1; i >= 0; i--) {
        if (numbers[i].size() == 1) {
            if (mapping[numbers[i][0]] == 0)
                out.push_back(numbers[i][0]);
            else
                out.push_back(mapping[numbers[i][0]]);
        } else {
            if (mapping[numbers[i][1]] != 0)
                mapping[numbers[i][0]] = mapping[numbers[i][1]];
            else
                mapping[numbers[i][0]] = numbers[i][1];
        }
    }
    reverse(out.begin(), out.end());
    
    for (int i = 0; i < out.size(); i++)
        cout << out[i] << " ";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
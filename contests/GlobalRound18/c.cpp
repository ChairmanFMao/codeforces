#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try with a WA on pretest 2
// I think with the length of the string and number of test cases that brute force isn't an option
// Failed as memory limit exceeded on pretest 2
// TLE on pretest 2 somehow
// I think that I was close to getting this but idk
// Even using a priority queue, the code still times out on test 2

map<string,int> mapping;
int length;

void permutations(string current) {
    if (length == current.size()) {
        mapping[current] = INT_MAX;
        return;
    }
    permutations(current + "0");
    permutations(current + "1");
}

string invert(int exempt, string s) {
    string out = "";
    for (int i = 0; i < s.size(); i++) {
        if (i == exempt)
            out += s[i];
        else
            out += s[i] == '0' ? "1" : "0";
    }
    return out;
}

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    length = n;
    mapping.clear();
    permutations("");
    priority_queue<pair<int,string>> positions;
    positions.push({0,a});
    mapping[a] = 0;
    while (!positions.empty()) {
        pair<int,string> current = positions.top();
        if (current.second == b)
            break;
        positions.pop();
        current.first *= -1;
        for (int i = 0; i < n; i++)
            if (current.second[i] == '1') {
                string next = invert(i,current.second);
                if (mapping[next] > current.first+1) {
                    mapping[next] = current.first+1;
                    positions.push({-(current.first+1), next});
                }
            }  
    }
    if (mapping[b] != INT_MAX)
        cout << mapping[b] << "\n";
    else
        cout << -1 << "\n";
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
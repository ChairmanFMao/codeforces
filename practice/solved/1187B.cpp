#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Initially got some ideas, not sure about the binary search tag tho
// Failed first try because I left some debugging output when I submitted
// Failed second try with a TLE on test 4 due to the O(n^2) time complexity of my linear search
// Failed third try with a TLE on test 6, even with the binary search, potentially my check function is too slow, it is linear tho
// Failed fourth try with TLE on test 6 again even with some optimisations
// Failed fifth try with TLE on test 6, so I am going to look at the tutorial to see if there are any things that I am doing wrong
// After looking at the tutorial, I need to redesign the algorithm
// Accepted sixth try! This was accomplished with the algoithm outlined in the editorial for the problem

void solve() {
    int n, m;
    string s;
    cin >> n >> s >> m;
    string names[m];
    for (int i = 0; i < m; i++)
        cin >> names[i];
    
    map<char,vector<int>> locations;
    for (int i = 0; i < s.size(); i++)
        locations[s[i]].push_back(i);
    
    for (int i = 0; i < m; i++) {
        int last = 0;
        set<char> characters;
        map<char,int> occurs;
        for (int j = 0; j < names[i].size(); j++) {
            characters.insert(names[i][j]);
            occurs[names[i][j]]++;
        }
        vector<char> unique(characters.begin(),characters.end());
        for (int j = 0; j < unique.size(); j++)
            last = max(last,locations[unique[j]][occurs[unique[j]]-1]);
        cout << last+1 << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try with WA test 4, this was due to an edge case
// Failed second try with WA test 6, this was due to another more complicated edge case
// Failed third try with WA test 10
// Failed fourth try, WA test 6
// Failed fifth try, WA test 2, silly mistake
// Failed sixth try, WA test 11
// Finally accepted on seventh try! There were many edge cases and my original idea didn't case to all of them
// I had to keep testing to find these edge cases leading to many failed submissions
// I think that I should try to come up with counter test cases to my code before submitting

int occurs(string occuring, string testing) {
    if (occuring.size() > testing.size())
        return 0;
    int appears = 0;
    for (int i = 0; i <= testing.size() - occuring.size(); i++)
        if (testing.substr(i,occuring.size()) == occuring)
            appears++;
    return appears;
}

int sharephrase(string s) {
    int largest = 0;
    for (int i = 1; i <= s.size()/2; i++)
        if (s.substr(0,i) == s.substr(s.size()-i))
            largest = max(largest,i);
    return largest;
}

void solve() {
    int n, k;
    string t;
    cin >> n >> k >> t;


    // Need to check the prefix of t and the suffix to see if they are compatable
    string out = "";
    if (t.size() == 1) {
        for (int i = 0; i < k; i++)
            out += t;
    }

    else if (sharephrase(t)) {
        int number = sharephrase(t);
        out += t;
        string word = t.substr(number);
        int ptr = 0;
        while (occurs(t,out) < k) {
            out += word[ptr%word.size()];
            ptr++;
        }
    }

    // This deals with the case that they are not compatable
    else {
        int ptr = 0;
        while (occurs(t,out) < k) {
            out += t[ptr%t.size()];
            ptr++;
        }
    }
    
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
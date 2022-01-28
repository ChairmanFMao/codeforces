
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Unsure how to optmise my technique from the first half of the problem
// I feel like you should be able to work out which people are imposters
// from just a single pass over the numbers but, I can't think of a way.
// Had to look at solution, but this is a very nice way to make it more
// efficient by splitting up all of the members into groups of three
// Very happy that I managed to implement the solution well, just a little sad
// that I didn't manage to think of the logic myself ;-;

void solve() {
    int n;
    cin >> n;
    vector<int> queries(n/3);
    int ptr = 1, otherptr = 0;

    vector<int> imp, crew;

    while (ptr < n) {
        cout << "? " << ptr << " " << ptr+1 << " " << ptr+2 << "\n";
        cout.flush();
        cin >> queries[otherptr];

        if (!queries[otherptr] && !imp.size()) {
            imp = {ptr,ptr+1,ptr+2};
        } else if (queries[otherptr] && !crew.size()) {
            crew = {ptr,ptr+1,ptr+2};
        }
        otherptr++;
        ptr+=3;
    }

    vector<int> together;
    for (int i : imp)
        together.push_back(i);
    for (int i : crew)
        together.push_back(i);

    sort(together.begin(),together.end());
    
    int imposter = -1, crewmate = -1;
    bool prev = queries[together[0]/3], current;

    for (int i = 1; i < 4; i++) {
        if (i != 3) {
            cout << "? " << together[i] << " " << together[i+1] << " " << together[i+2] << "\n";
            cout.flush();
            cin >> current;
        } else
            current = queries[together[i]/3];
        if (current != prev) {
            imposter = prev ? together[i+2] : together[i-1];
            crewmate = prev ? together[i-1] : together[i+2];
            break;
        }
    }

    // At this point we know the location of one imposter and one crewmate in n/3 + 2 moves

    vector<int> out;
    out.push_back(imposter);
    bool first;
    // This goes through all of the triplets
    for (int i = 1; i < n; i+=3) {
        // This is if one of the numbers in the triplet is either the crewmate or imposter
        if (i == crewmate || i+1 == crewmate || i+2 == crewmate || i == imposter || i+1 == imposter || i+2 == imposter) {
            for (int j = i; j < i+3; j++) {
                if (j == crewmate || j == imposter)
                    continue;
                cout << "? " << crewmate << " " << imposter << " " << j << "\n";
                cout.flush();
                cin >> first;
                if (!first)
                    out.push_back(j);
            }
        }
        // If majority imposters
        else if (!queries[i/3]) {
            cout << "? " << crewmate << " " << i << " " << i+1 << "\n";
            cout.flush();
            cin >> first;
            // This means that one of the first two was a crewmate
            if (first) {
                out.push_back(i+2);
                cout << "? " << crewmate << " " << imposter << " " << i << "\n";
                cout.flush();
                cin >> first;
                out.push_back(first ? i+1 : i);
            } 
            // This means that both of the first two are imposters
            else {
                out.push_back(i);
                out.push_back(i+1);
                cout << "? " << crewmate << " " << imposter << " " << i+2 << "\n";
                cout.flush();
                cin >> first;
                if (!first)
                    out.push_back(i+2);
            }
        } 
        // If majority crewmates
        else {
            cout << "? " << imposter << " " << i << " " << i+1 << "\n";
            cout.flush();
            cin >> first;
            // In this case the first two are crewmates
            if (first) {
                cout << "? " << imposter << " " << crewmate << " " << i+2 << "\n";
                cout.flush();
                cin >> first;
                if (!first)
                    out.push_back(i+2);
            }
            // In this case one of the first two is an imposter
            else {
                cout << "? " << imposter << " " << crewmate << " " << i << "\n";
                cout.flush();
                cin >> first;
                out.push_back(first ? i+1 : i);
            }
        }
    }
    
    cout << "! " << out.size() << " ";
    for (int i : out)
        cout << i << " ";
    cout << "\n";
}

int main(void) {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Unsure how to take in an indefinite number of words
// This formatting is horrible
// Just store the correct output and print it if there is an error
// want to rearrange the bit after as well

void solve() {
	string s;
	vector<string> words, startEnd;
	map<string,vector<string>> out;
	int flag = 0, ptr = 0, good = 1;
	string current = "";
	while (cin >> s) {
		if (s.substr(0,7) == "\\begin{")
			flag = 1;

		if (flag) {
			if (s.substr(0,7) == "\\begin{" || s.substr(0,5) == "\\end{") {
				startEnd.push_back(s);
			}
			else if (s[0] == '\\') {
				string temp = "";
				int flag2 = 0;
				for (int i = 0; i < sz(s)-1; i++) {
					if (s[i] == '}')
						flag2 = 2;
					if (flag2 == 1)
						temp += s[i];
					if (s[i] == '{')
						flag2 = 1;
				}
				if (temp != words[ptr])
					good = 0;
				ptr++;
				current = temp;
				out[current].emplace_back(s);
			} else
				out[current].emplace_back(s);

		} else if (s[0] == '\\') {
			string temp = "";
			int flag2 = 0;
			for (int i = 0; i < sz(s); i++) {
				if (s[i] == '}')
					flag2 = i;
				if (flag2 == 1)
					temp += s[i];
				if (s[i] == '{')
					flag2 = 1;
			}
			words.emplace_back(s.substr(6,flag2-6));
		}
	}

	if (good) {
		cout << "Correct\n";
		return;
	}

	cout << "Incorrect\n";
	cout << startEnd[0] << "\n";
	for (int i = 0; i < sz(words); i++)
		for (int j = 0; j < sz(out[words[i]]); j++)
			cout << out[words[i]][j] << " \n"[j==sz(out[words[i]])-1];

	cout << startEnd[1] << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}


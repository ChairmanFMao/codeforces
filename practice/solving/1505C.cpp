#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	string s;
	cin >> s;
	vector<int> numbers;
	for (char c : s)
		numbers.push_back(c-65);

	bool good = 1;
	for (int i = 2; i < (int)s.size(); i++) {
		if ((numbers[i-2] + numbers[i-1]) % 26 != numbers[i])
			good = 0;
	}
	
	cout << (good ? "YES" : "NO") << "\n";
}


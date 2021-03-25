#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

void solve1_1() {
	string s;
	cin >> s;
	unordered_set<char> mp;
	for (char c : s) {
		if (! (mp.find(c) == mp.end()))
		{
			cout << "False\n";
			return ;
		}
		mp.insert(c);
	}
	cout << "All unique\n";
}

void solve1_1acc() {
#define a s
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	for1(i, s.length() - 1) if (s[i] == a[i - 1])	{
		cout << "False\n";
		return;
	}
	cout << "True\n";
}

void solve1_2() {
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.length() != s2.length()) {
		cout << "False\n";
		return;
	}
	int ar[26];
	memset(ar, 0, sizeof ar);
	for (auto c : s1) {
		ar[c - 'a']++;
	}
	for (auto c : s2) {
		if (ar[c - 'a'] == 0) {
			cout << "False\n";
			return;
		}
		ar[c - 'a']--;
	}
	cout << "Yes\n";
}

void solve1_3() {
	string s, s2;
	// cin.ignore();
	getline(cin, s);
	int n;	cin >> n;
	for0(i, n) {
		if (s[i] == ' ')
			s2 += "%20";
		else
			s2 += s[i];
	}
	cout << s2 << "\n";
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// solve1_1();
	// solve1_1acc();
	// solve1_2();
	solve1_3();

	return 0;
}
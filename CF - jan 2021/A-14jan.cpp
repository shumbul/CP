#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void solve1() {
	int t;	cin >> t;
	while (t--) {
		int n, d;	cin >> n >> d;
		int ar[n];
		bool f = 0;
		for0(i, n)	{
			cin >> ar[i]; if (ar[i] > d) f = 1;
		}
		if (f == 0) {
			cout << "YES\n";
			continue;
		}

		sort(ar, ar + n);
		if (ar[0] + ar[1] > d)	cout << "NO\n";
		else cout << "YES\n";
	}

}

int lcm(int a, int b) {
	return (a / gcd(a, b) * b);
}

void solve2() {
	int t;	cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1.length() < s2.length()) {
			string tmp = s1;	s1 = s2;	s2 = tmp;
		}
		int l1, l2;
		l1 = s1.length(), l2 = s2.length();
		//l1>l2
		string s;
		for (int i = 0; i < l1 * l2; i++) {
			s += s2;
		}
		int flag = 1;
		// cout << s << "  " << s2 << endl;
		for (int i = 0; i < l1 * l2; i += l1) {
			for (int j = 0; j < l1; j++) {
				if (s[i + j] != s1[j]) {
					flag = 0;
					break;
				}
			}
			if (flag == 0) break;
		}
		if (flag == 0) cout << "-1\n";
		else {
			int l = lcm(l1, l2);
			int mult = l / l1;
			s = s1;
			for (int i = 1; i < mult; i++) {
				s += s1;
			}
			cout << s << "\n";
		}
	}
}

void solve3() {

}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// solve1();
	// solve2();
	solve3();

	return 0;
}
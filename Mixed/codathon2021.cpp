#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define inar(mar,n) for(int i=0; i<n; i++) cin>>mar[i];
#define suma(mar,n) for(int i=0; i<n; i++) sum+=mar[i];
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define forr(i,n) for(int i=n-1; i>=0; i--)
#define For(i,a,n) for(int i=(a);i<=(n);i++)
#define rof(i,a,b) for(int i=a;i<=b;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Max(a,b) a = max(a,b)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7, inf = 1e10 + 1;
ll gcd (ll a, ll b) {return ( a ? gcd(b % a, a) : b );}
ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

void solve_day1() {
	int t;	cin >> t;
	while (t--) {
		int s = -inf;
		int e = inf;
		int n;	cin >> n;
		bool lc = 0, rc = 0;
		if (n < 2)	{
			cout << "-1\n";
			continue;
		}
		while (n--) {
			char ch; int lim;
			cin >> ch >> lim;
			if (ch == 'R')	{
				rc = 1;
				if (lim == e) {
					cout << e << "\n";
					continue;
				}
				if (lim > e) {
					cout << "-1\n";
					continue;
				}
				s = max(lim, s);
			}
			else if (ch == 'L')	{
				lc = 1;
				if (lim == s) {
					cout << s << "\n";
					continue;
				}
				if (lim < s) {
					cout << "-1\n";
					continue;
				}
				e = min(lim, e);
			}
		}
		// cout << s << " " << e << " \n";
		if (lc == 0 || rc == 0) { cout << "-1\n"; continue; }
		int ans = e - s - 1;
		if (e > s + 1)
			cout << ans << "\n";
		else cout << "-1\n";
	}
}

const int MAXN = 50;
int a[MAXN];
int n;
unordered_map<int, int> modulo;

bool check(int factor) {
	modulo.clear();

	For(i, 1, n) modulo[a[i] % factor]++;

	For(i, 1, n) {
		if (a[i] % factor == factor - (a[i] % factor) || a[i] % factor == 0) {
			if (modulo[a[i] % factor] % 2) return false;
		} else if (modulo[a[i] % factor] != modulo[factor - (a[i] % factor)]) return false;
	}

	return true;
}

void solve_day3() {
	cin >> n;
	For(i, 1, n) cin >> a[i];

	int ans = 1;

	For(k, 2, n) {
		int val = a[1] + a[k];

		for (int i = 1; i * i <= val; i++) {
			if (val % i != 0) continue;
			if (check(i)) Max(ans, i);
			if (check(val / i)) Max(ans, val / i);
		}
	}
	cout << ans << endl;
}

void solve_day2() {

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		int arr[n];	inar(arr, n);
		int ans = 0;
		int* xorArr = new int[n];
		unordered_map<int, int> mp;
		xorArr[0] = arr[0];
		for (int i = 1; i < n; i++)
			xorArr[i] = xorArr[i - 1] ^ arr[i];
		for (int i = 0; i < n; i++) {
			int tmp = 2 ^ xorArr[i];
			ans = ans + ((long long)mp[tmp]);
			if (xorArr[i] % 2 == 0)
				ans++;
			mp[xorArr[i]]++;
		}
		cout << ans << "\n";
	}
}

void solve_day6() {
	int n, m, k;	cin >> n >> m >> k;
	map<pair<int, int>, vector<string>> mp;
	for0(i, n) {
		int a, b;	cin >> a >> b;
		int c;	cin >> c;
		pair<int, int> p = {1, a};
		if (mp.find(p) != mp.end()) {
			for (auto q : mp[p]) {
				string st = q + "+" + to_string(c);
				mp[ {1, b}].pb(st);
			}
		}
		else
			mp[ {a, b}].pb(to_string(c));
	}
	pair<int, int> p = {1, m};
	int ans = 0;

	if (mp.find(p) == mp.end())
		cout << -1 << "\n";
	else
	{
		vector<string> v;
		v = mp[p];
		vi r;
		for (auto it : mp) {
			cout << it.ff.ff << "-" << it.ff.ss << "  " << "\n";
			for (auto ir : it.ss) {
				cout << ir << "  -> ";
				string s = ir;
				for0(i, s.length()) {
					string st;
					if (s[i] == '+') {
						sort(all(r));
						r[r.size() - 1] /= k;
						int z = 0;
						ans = min(ans, accumulate(all(r), z));
						r.clear();
						continue;
					}
					while (s[i] != '+' && i < s.length()) {
						st += s[i];
					}
					r.pb(stoi(st));
				}
			}
		}

		cout << ans << "\n";
	}


}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// partially accepted! -1,2
	// solve_day1();
	// solve_day3();
	// solve_day2();
	solve_day6();

	return 0;
}
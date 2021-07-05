#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define inar(arr,n) for(int i=0; i<n; i++) cin>>arr[i];
#define suma(arr,n) for(int i=0; i<n; i++) sum+=arr[i];
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define forr(i,n) for(int i=n-1; i>=0; i--)
#define rof(i,a,b) for(int i=a;i<=b;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;
ll gcd (ll a, ll b) {return ( a ? gcd(b % a, a) : b );}
ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

void solveA() {
	int t;	cin >> t;
	while (t--) {
		int p1, p2;	cin >> p1 >> p2;
		string t, s;	cin >> s;
		if (p1 > 0) {
			t = "";
			// remove all Ds
			for (auto c : s) {
				if (c == 'L') {
					continue;
				}
				t +=  (c);
			}
			s = t;
		}
		else if (p1 < 0) {
			t = "";
			// remove all Us
			for (auto c : s) {
				if (c == 'R') {
					continue;
				}
				t +=  (c);
			}
			s = t;
		}
		if (p2 > 0) {
			t = "";
			// remove all Ls
			for (auto c : s) {
				if (c == 'D') {
					continue;
				}
				t +=  (c);
			}
			s = t;
		}
		if (p2 < 0) {
			t = "";
			// remove all Rs
			for (auto c : s) {
				if (c == 'U') {
					continue;
				}
				t +=  (c);
			}
			s = t;
		}
		// cout << s << "---> \n";
		multiset<char> mset;
		for (auto c : s) {
			mset.insert(c);
		}
		bool ans = true;
		if (p1 > 0) {
			if (mset.count('R') < p1)
				goto last;
		}
		else if (p1 < 0) {
			if (mset.count('L') < -p1)
				goto last;
		}

		if (p2 > 0) {
			if (mset.count('U') < p2)
				goto last;
		}
		else if (p2 < 0) {
			if (mset.count('D') < -p2)
				goto last;
		}

		cout << "YES\n";
		continue;
last:
		cout << "NO\n";
	}
}

void solveB() {
	int t;	cin >> t;
	while (t--) {
		int n, k;	cin >> n >> k;
		if (n < 2)	{ cout << "-1\n"; continue; }
		vi ar(n);
		for0(i, n)	cin >> ar[i];
		int ans = 1;
		while (k--) {
			ans = 1;
			int i;
			for (i = 0; i < n - 1; i++) {
				if (ar[i + 1] <= ar[i]) ans++;
				else {
					ar[i]++;
					break;
				}
			}
		}
		// for (auto a : ar) {
		// 	cout << a << " -> ";
		// }
		if (ans == n) ans = -1;
		cout << ans << "\n";
	}
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// solveA();
	solveB();


	return 0;
}
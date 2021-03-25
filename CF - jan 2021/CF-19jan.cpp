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
#define endl "\n"
const int mod = 1e9 + 7;
ll gcd (ll a, ll b) {return ( a ? gcd(b % a, a) : b );}
ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

void solveA() {
	//we use greedy

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		string b;	cin >> b;
		string c;
		int prev = -1, dig;
		for (char ch : b) {
			dig = 1;
			if (dig + ch == prev) {
				dig = 0;
			}
			c += to_string(dig);
			prev = dig + ch;
		}
		cout << c << "\n";
	}
}

vi primes;
bool prime[100001];

void sieve() {
	memset(prime, true, sizeof prime);
	int n = sizeof(prime) - 1;
	for (int p = 2; p * p <= n ; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	for (int p = 2; p <= n; p++)
		if (prime[p])
			primes.pb(p);
}

void solveB() {
	sieve();

	int t;	cin >> t;
	while (t--) {
		int d;	cin >> d;
		int ans = -1;
		for0(i, primes.size()) {
			int a = primes[i];
			if (a > d) {
				for (int j = i + 1; j < primes.size(); j++) {
					if (primes[j] - a >= d) {
						ans = a * primes[j];
						break;
					}
				}
				break;
			}
		}
		cout << ans << "\n";
	}
}

void solveC() {
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		multiset<int, greater<int>> mset, ms, prevmset;
		vi ar(2 * n);
		for0(i, 2 * n)
		{ cin >> ar[i]; mset.insert(ar[i]); }
		int strt;
		bool flag = 0;
		int x, a, b;

		sort(all(ar), greater<int>());

		for (strt = 1; strt < 2 * n; strt++) {
			ms = mset;
			a = ar[0];
			b = ar[strt];
			x = b + a;
			while (!ms.empty()) {
				a = *ms.begin();
				b = x - a;
				// V. V. IMP
				ms.erase(ms.find(a));
				if (ms.find(b) == ms.end()) {
					break;
				}
				ms.erase(ms.find(b));
				x = max(a, b);
			}
			if (ms.size() == 0) {
				flag = 1;
				// => this was the required ans set
				break;
			}
		}
		if (flag == 0) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			a = ar[0];
			ms = mset;
			b = ar[strt];
			x = b + a;
			cout << x << "\n";
			while (!ms.empty()) {
				a = *ms.begin();
				ms.erase(ms.find(a));
				b = x - a;
				ms.erase(ms.find(b));
				x = max(a, b);
				cout << a << " " << b << "\n";
			}
		}
	}
}

void solveD() {

}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// solveA();
	// solveB();
	// solveC();
	solveD();

	return 0;
}
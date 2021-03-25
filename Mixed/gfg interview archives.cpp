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

bool primes[100001];

void sieve(int n) {
	memset(primes, 1, n + 1);
	primes[0] = primes[1] = 0;
	for (int i = 2; i * i <= n; i++) {
		for (int j = 2; j * i <= n; j++) {
			primes[i * j] = 0;
		}
	}
}

void solve_euler() {
	int n;	cin >> n;
	if (n == 1) { cout << 1 << endl;	return; }
	sieve(n);
	if (primes[n])	cout << n - 1 << endl;
	else {
		float ans = n;
		for (int p = 2; p * p <= n; p++) {
			if (n % p == 0) {
				while (n % p == 0)	n /= p;
			}
			ans *= (1.0 - 1.0 / p);
		}
		ans *= (1.0 - 1.0 / n);
		cout << ans << "\n";
	}
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve_euler();

	return 0;
}
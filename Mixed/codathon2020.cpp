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
#define rof(i,a,b) for(int i=a;i<=b;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;
ll gcd (ll a, ll b) {return ( a ? gcd(b % a, a) : b );}
ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

// void solve_day1() {
// 	int n, k;	cin >> n >> k;
// 	int ar[n];
// 	for0(i, n) cin >> ar[i];
// 	int s = 0, e = n - 1, cnt = 0;
// 	while (s <= e) {
// 		// cout << s << " -> " << e << " " << ar[s] << '\n';
// 		if (s == e) {
// 			if (ar[s] <= k) cnt++; break;
// 		}
// 		if (ar[s] > k && ar[e] > k) break;
// 		while (s < e && ar[s] <= k) {
// 			s++;
// 			cnt++;
// 		}
// 		while (s < e && ar[e] <= k) {
// 			e--;
// 			cnt++;
// 		}
// 	}
// 	cout << n - cnt << "\n";
// }

void solve_day2() {
	int n, i, j;
	cin >> n;
	int mar[n + 2][n + 2] = {0};
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> mar[i][j];
		}
	}
	int q, s = 0;
	cin >> q;
	int t, a, b, c, min = 10001, max = 0, k = 0;
	while (q--) {
		cin >> t >> a >> b >> c;
		k = k ^ c;
		if (a < min)
			min = a;
		if (b > max)
			max = b;
	}
	for (i = min; i <= max; i++) {
		mar[i][i] = mar[i][i] ^ k;
	}
	for (i = 1; i <= n; i++)
		s += mar[i][i];
	cout << s << "\n";
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// solve_day1();
	solve_day2();

	return 0;
}
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

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, t;	cin >> n >> t;
	int ar[n];	for0(i, n)	ar[i] = 0;
	while (t--) {
		int x;	cin >> x;
		ar[x - 1] = 1;
	}
	vi v;
	int w = 0, mini = n + 1;
	for0(i, n)	{
		// cout << ar[i] << " -> mmm \n";
		if (i == n - 1 && ar[i] == 0) {
			w++;
			v.pb(w);
			mini = min(w, mini);
			break;
		}
		if (ar[i] == 0)	w++;
		else {
			if (w) {
				v.pb(w);
				// cout << w << " ";
				mini = min(w, mini);
			} w = 0;
		}
	}
	if (mini > n ) {
		// no whites
		cout << 0;
		return 0;
	}
	if (mini == n)	{
		cout << 1;
		return 0;
	}
	int ans = 0;
	for (auto a : v) {

		ans += a / mini;
		if (a % mini) ans++;
	}
	cout << ans;
	return 0;
}
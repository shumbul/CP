//knapsack
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int int64_t
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

const int inf = 1e18L + 5;

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, cap;
	cin >> n >> cap;
	int wt[n], val[n];
	for0(i, n)	cin >> wt[i] >> val[i];
	int totalval = accumulate(val, val + n, 0);
	vi dp(totalval + 1, inf);
	//dp[i] denotes minimum weight at val i
	dp[0] = 0;
	for0(i, n) {
		for (int val_already = totalval - val[i]; val_already >= 0; --val_already) {
			dp[val_already + val[i]] = min(dp[val_already + val[i]], dp[val_already] + wt[i]);
		}
	}
	int ans = 0;
	for0(i, totalval + 1)	//iterating over value
	if (dp[i] <= cap)
		ans = max(ans, i);
	cout << ans;
	return 0;
}
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

string find_lcs(string a, string b) {
	int r = a.length(), c = b.length();
	int dp[r + 1][c + 1];
	for0(i, r + 1) {
		for0(j, c + 1) {
			if (i == 0 || j == 0)	dp[i][j] = 0;
			else {
				if (a[i - 1] == b[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int lcslen = dp[r][c];
	string lcs;
	int i = r, j = c;
	while (i > 0 && j > 0) {
		if (a[i - 1] == b[j - 1]) {
			lcs += a[i - 1];
			i--, j--;
		}
		else {
			dp[i - 1][j] > dp[i][j - 1] ? i-- : j--;
		}
	}
	reverse(lcs.begin(), lcs.end());
	return lcs;
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string a, b;	cin >> a >> b;
	cout << find_lcs(a, b) << endl;

	return 0;
}
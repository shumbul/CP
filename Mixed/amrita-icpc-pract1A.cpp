//https://codedrills.io/contests/amrita-icpc-practice-session-1/problems/find-max-ranges

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

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		int ar[n];
		inar(ar, n);
		int i = 0, j = 0;
		vector<pair<int, int>> ans(n, mp(0, 0));

		for (int k = 1; k < n; k++) {
			i = k - 1;
			while (ar[i] <= ar[k] && i >= 0)	i--;
			i++;
			ans[k].ff = i;
		}

		for (int k = 0; k < n - 1; k++) {
			j = k + 1;
			while (ar[j] <= ar[k] && j < n)	j++;
			j--;
			ans[k].ss = j;
		}

		ans[n - 1].ss = n - 1;

		for (auto a : ans) {
			string s = to_string(a.ff) + " " + to_string(a.ss) + "\n";
			cout << s;
		}
	}


	return 0;
}
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

int ans;
bool allequal(vi v) {
	if (v.size() == 1)	return true;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] != v[0])	return false;
	}
	return true;
}

void solve(vi v, int& trial) {
	// for (int i : v)	cout << i << " ";
	// cout << "Trial :" << trial << endl;
	if (ans == 0)	return;
	if (allequal(v) || v.size() < 2)	{
		ans = min(ans, trial);
		// cout << "Ans " << ans << endl;
		return;
	}
	if (v.size() == 2 && !allequal(v)) {
		trial = trial + 1;
		ans = min(ans, trial);
		// cout << "Ans " << ans << endl;
		trial = trial - 1;
		return;
	}
	int n = v.size();
	for (int i = 1; i < n - 1; i++) {
		//left
		{
			int k = v[i];
			v[i - 1] += v[i];
			v.erase(v.begin() + i);
			trial++;
			solve(v, trial);
			trial--;
			v.insert(v.begin() + i, k);
			v[i - 1] -= v[i];
		}
		//right
		{
			int k = v[i];
			v[i + 1] += v[i];
			v.erase(v.begin() + i);
			trial++;
			solve(v, trial);
			trial--;
			v.insert(v.begin() + i, k);
			v[i + 1] -= v[i];
		}
	}

	// cout << "returning " << ans << endl;
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;	cin >> t;
	while (t--) {
		ans = INT_MAX;
		int n;	cin >> n;
		vector<int> vec;
		int x;	for0(i, n) {
			cin >> x;	vec.pb(x);
		}
		n = 0;
		solve(vec, n);
		cout << ans << endl;
	}

	return 0;
}
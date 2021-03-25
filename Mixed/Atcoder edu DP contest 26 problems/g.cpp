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

vi ar[100001];
int ans, in_deg[100001], dist[100001];
bool visited[100001];

void dfs(int i) {
	ans = max(ans, dist[i]);
	if (ar[i].size() == 0)	return;
	// visited[i] = 1;
	// cout << i << " -> ";
	for (auto a : ar[i]) {
		if (!visited[a] && ar[a].size() == 0) ans = max(ans, dist[i] + 1);
		else if (!visited[a])	{ dist[a] = dist[i] + 1; dfs(a); dist[a] = dist[i] - 1;}
	}
	visited[i] = 0;
	// cout << " break " << ans << endl;
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, e;
	cin >> n >> e;
	while (e--) {
		int a, b;	cin >> a >> b;
		ar[a].pb(b);
		in_deg[b]++;
	}

	for1(i, n) {
		if (!visited[i] && ar[i].size() == 0 && in_deg[i] == 0 ) ans = max(ans, dist[i] + 1);
		else if (!visited[i] && in_deg[i] == 0)	{
			dfs(i);
			for1(j, n)	visited[j] = 0;
			visited[i] = 1;
		}
		// cout << endl;
	}
	// for1(i, n)	cout << "dist " << dist[i] << " ";
	cout << ans;

	return 0;
}
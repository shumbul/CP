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

vi choice[100001];
int taken[100001], done[100001];
set<int> married;

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		married.clear();
		for1(i, n)	{
			choice[i].clear();
			taken[i] = 0, done[i] = 0;
		}
		for1(i, n) {
			int k;	cin >> k;
			for1(j, k) {
				int temp;	cin >> temp;
				choice[i].pb(temp);
				if (taken[temp] == 0 && done[i] == 0) {
					done[i] = 1, taken[temp] = 1;
					married.insert(i);
					// cout << "lot " << i << " " << temp << endl;
				}
			}
		}
		// for1 (i, n) {
		// 	for (auto x : choice[i])	cout << x << " ";
		// 	cout << endl;
		// }
		if (married.size() == n)	{ cout << "OPTIMAL" << endl; continue; }
		int flag = 0;
		for1(i, n) {
			if (done[i] == 0) {
				for1(j, n) {
					if (taken[j] == 0 && find(all(choice[i]), j) == choice[i].end())
					{
						if (married.size() < n)
							cout << "IMPROVE" << endl;
						cout << i << " " << j << endl;
						flag = 1; done[i] = 1;	taken[j] = 1;
						married.insert(i);
						break;
					}
				}
			}
			if (flag == 1)break;
		}


	}



	return 0;
}
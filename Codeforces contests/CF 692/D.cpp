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

int x, y;

int CountZeros(int n)
{
	// declare bitset of 64 bits
	bitset<64> bit;

	// set bitset with the value
	bit |= n;

	int zero = 0;

	for (int i = 0; i < 64; i++) {
		if (bit[i] == 0)
			zero++;
		// if '1' comes then break
		else
			break;
	}

	return zero;
}

int CountOnes(int n)
{
	// declare bitset of 64 bits
	bitset<64> bit;

	// set bitset with the value
	bit |= n;

	int zero = 0;

	for (int i = 0; i < 64; i++) {
		if (bit[i] == 1)
			zero++;
		// if '1' comes then break
		else
			break;
	}

	return zero;
}

int countp(string s, string b)
{
	int ar0[s.length()], ar1[s.length()];

	if (b == "01") {
		for0(i, s.length() - 1) {
			string k(s.begin() + i + 1, s.end());
			cout << " k from 01 " << k ;
			ar1[i] = CountOnes(stoi(k));
			cout << " -> " << ar1[i] << endl;
		}
		int res = 0;
		for0(i, s.length()) {
			if (s[i] == '0') {
				res ++;
			}
		}
		cout << "res 1 " << res << endl;
		return res * x;
	}
	if (b == "10") {
		for0(i, s.length() - 1) {
			string k(s.begin() + i + 1, s.end());
			ar0[i] = CountZeros(stoi(k));
			// ar1[i]=CountOnes(stoi(k));
		}
		int res = 0;
		for0(i, s.length()) {
			if (s[i] == '0') {
				res ++;
			}
		}
		return res * y;
	}
}

int solve(string s) {
	if (s.find("?") == s.npos) {
		int cmt = 0;
		int ans = 0;
		cmt = countp(s, "01");
		// cout << "cmt1 in " << s << " is " << ans << endl;
		ans += (cmt);
		cmt = countp(s, "10");
		// cout << "cmt2 in " << s << " is " << ans << endl;
		ans += (cmt);
		cout << "ans in " << s << " is " << ans << endl;
		// cout << s << endl;
		return ans;
	}
	for0(i, s.length()) {
		if (s[i] == '?')
		{
			int v1, v2;
			s[i] = '0';	v1 = solve(s);
			s[i] = '1';	v2 = solve(s);
			if (v1 < v2)	return v1;
			else return v2;
		}
	}
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;	cin >> s;
	cin >> x >> y;
	cout << solve(s);

	return 0;
}
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

bool solve(string s) {
	int len = s.length();
	if (len == 0)	return true;
	if (len % 2)	return false;
	if (s[0] == ')' || s[len - 1] == '(') return false;
	if (s.find(')') == s.npos && s.find('(') == s.npos) return true;
	// for (int i = 0; i < len - 1; i++)	{
	// 	if (s[i] == '('  || s[i] == '?' && s[i + 1] == ')' || s[i + 1] == '?')
	// 		s.erase(s.begin() + i, s.begin() + i + 2);
	// }
	// s.erase(s.begin());
	// s.erase(s.end());

	if (s.length() == 0)	return true;
	stack<char> r;
	r.push(s[0]);
	int i = 1;
	while (i < s.length()) {
		if (s[i] == ')')	{
			if (r.empty())	return false;
			// cout << r.top() << endl;
			r.pop();
		}
		else
			r.push(s[i]);
		i++;
	}
	if (r.size() % 2 == 0)	return true;
	if (!r.empty())
		while (!r.empty() && r.top() == '?')	r.pop();
	if (!r.empty()) {
		// cout << s << " " << " r.top()" << endl;
		return false;
	}

	return true;
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;	cin >> t;
	while (t--) {
		string s;	cin >> s;
		bool b = solve(s);
		if (b)	cout << "yes\n";
		else cout << "no\n";
	}


	return 0;
}
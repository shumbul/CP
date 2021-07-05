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

void solveA() {
	int t;	cin >> t;
	while (t--) {
		string s;	cin >> s;
		int n = s.length();
		if (n == 1) {
			if (s[0] > 'a')
				s[0] = 'a';
			else s[0] = 'b';
		}
		else {
			for (int i = 0; i < n; i++) {
				if (i % 2 == 0) {
					if (s[i] > 'a')	s[i] = 'a';
					else (s[i] = 'b');
				}
				else {
					if (s[i] < 'z')	s[i] = 'z';
					else s[i] = 'y';
				}
			}
		}
		cout << s << endl;
	}
}

void solveA_12feb() {
	int t;	cin >> t;
	while (t--) {
		int a, b;	cin >> a >> b;
		int steps = 0;
		bool c = 1;
		while (a) {
			if (b < 2)	b++;
			else {
				a /= b;
			}
			steps++;
		}
		cout << steps << "\n";
	}
}

void solve()
{
	string str;	cin >> str;
	/* Number of subsequences is (2**n -1)*/
	int n = str.length();
	unsigned int opsize = pow(2, n);
	int res = 0;
	set<string> st;

	/* Generate all subsequences of a given string.
	   using counter 000..1 to 111..1*/
	for (int counter = 1; counter < opsize; counter++)
	{
		string subs = "";
		for (int j = 0; j < n; j++)
		{
			/* Check if jth bit in the counter is set
			    If set then print jth element from arr[] */
			if (counter & (1 << j))
				subs.push_back(str[j]);
		}		/* Print all permutations of current subsequence */
		do
		{
			// cout << subs << " ";
			st.insert(subs);
			res++;
		}
		while (next_permutation(subs.begin(), subs.end()));
	}
	cout << st.size() << "\n";
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// solveA();
	// solveA_12feb();
	solve();

	return 0;
}
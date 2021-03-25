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

vi primes;
bool prime[100001];

void ALGO_sieve() {
	memset(prime, true, sizeof prime);
	int n = sizeof(prime) - 1;
	for (int p = 2; p * p <= n ; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	for (int p = 2; p <= n; p++)
		if (prime[p])
			primes.pb(p);
}

void STL_multisets() {
	//DECLARE
	multiset<int> mset;

	//INSERT
	mset.insert(10);
	mset.insert(30);
	mset.insert(50);
	mset.insert(20);
	mset.insert(30);
	mset.insert(50);

	//PRINT
	cout << "Printing mset\n";
	multiset<int>::iterator it;
	for (it = mset.begin(); it != mset.end(); ++it) {
		cout << *it << "\n";
	}

	//ASSIGN TO ANOTHER MULTISET
	multiset<int, greater<int> > mset2(mset.begin(), mset.end());

	cout << "Printing mset2\n";
	for (it = mset2.begin(); it != mset2.end(); ++it) {
		cout << *it << "\n";
	}

	//ERASE
	// 1. removes elements from beginning till a given value is found
	mset2.erase(mset2.begin(), mset2.find(30));

	cout << "Printing mset2\n";
	for (it = mset2.begin(); it != mset2.end(); ++it) {
		cout << *it << "\n";
	}

	// 2. remove an element
	mset2.erase(20);

	cout << "Printing mset2\n";
	for (it = mset2.begin(); it != mset2.end(); ++it) {
		cout << *it << "\n";
	}
	// *NOTE* copies are also deleted by default
	//        otherwise mention this to delete single instance:
	mset2.erase(mset2.find(30));

	cout << "Printing mset2\n";
	for (it = mset2.begin(); it != mset2.end(); ++it) {
		cout << *it << "\n";
	}

	//COUNT
	cout << "COUNT of 50 in mset is: \n" << mset.count(50) << "\n";

	//LOWER AND UPPER BOUNDS
	cout << "Printing mset\n";
	for (it = mset.begin(); it != mset.end(); ++it) {
		cout << *it << "\n";
	}

	cout << "MSET Lower bound for 40: \n" << *mset.lower_bound(40) << "\n";
	cout << "MSET Lower bound for 50: \n" << *mset.lower_bound(50) << "\n";
	cout << "MSET Lower bound for 10: \n" << *mset.lower_bound(10) << "\n";
	cout << "MSET Lower bound for 30: \n" << *mset.lower_bound(30) << "\n";
	cout << "MSET Lower bound for 0: \n" << *mset.lower_bound(0) << "\n";
	cout << "MSET Lower bound for 70: \n" << *mset.lower_bound(70) << "\n";

	cout << "MSET Upper bound for 40: \n" << *mset.upper_bound(40) << "\n";
	cout << "MSET Upper bound for 50: \n" << *mset.upper_bound(50) << "\n";
	cout << "MSET Upper bound for 10: \n" << *mset.upper_bound(10) << "\n";
	cout << "MSET Upper bound for 30: \n" << *mset.upper_bound(30) << "\n";
	cout << "MSET Upper bound for 0: \n" << *mset.upper_bound(0) << "\n";
	cout << "MSET Upper bound for 70: \n" << *mset.upper_bound(70) << "\n";

}

struct compare {
	inline bool operator() (const string &s1, const string &s2) const {
		if (s1.length() == s2.length())
			return s1 < s2;
		return s1.length() > s2.length();
	}
};

void SORT() {
	vector<string> v;
	v = {"ale", "apple", "monkey", "plea"};
	// sort length wise and lexicographically smaller wise

	compare c;
	sort(v.begin(), v.end(), c);
	for (auto s : v) {
		cout << s << " ";
	}
	cout << '\n';
}

// Returns true if str1[] is a subsequence of str2[].
// m is length of str1 and n is length of str2
bool isSubSequence(string str1, string str2)
{
	int m = str1.length(), n = str2.length();

	int j = 0; // For index of str1 (or subsequence

	// Traverse str2 and str1, and compare current
	// character of str2 with first unmatched char
	// of str1, if matched then move ahead in str1
	for (int i = 0; i < n && j < m; i++)
		if (str1[j] == str2[i])
			j++;

	// If all characters of str1 were found in str2
	return (j == m);
}

void sub_sequence() {
	cout << "Subsequence \n";
	string s1, s2;	cin >> s1 >> s2;
	int b = isSubSequence(s1, s2) | isSubSequence(s2, s1);
	if (b) {
		cout << "yes\n";
	}
	else cout << "no\n";
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// ALGO_sieve();
	// STL_multisets();
	// SORT();
	sub_sequence();

	return 0;
}
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

void meetingRanges() {
	// ip:   [ (0, 1),  (3, 5),  (4, 8),  (10, 12),  (9, 10)]
	// op:   [ (0, 1),  (3, 8),  (9, 12)]

	/*
	- sort based on starttime, traverse Meet list, if endtime>=starttime of next, merge
	- use another list for ease! So that we don't have to merge, but just change the endtimes and proceed.
	- endtime of merged = max(endtimes of both)
	- while traversing, go from 1st to the 2nd last index
	*/
	vector<pair<int, int>> meet = { make_pair(0, 1), make_pair(1, 5), make_pair(10, 15), make_pair(9, 11)};
	sort(meet.begin(), meet.end());
	vector<pair<int, int>> merge_meets(meet.begin(), meet.begin() + 1);
	for (auto meets : vector<pair<int, int>>(meet.begin() + 1, meet.end())) {
		if (merge_meets[merge_meets.size() - 1].ss >= meets.ff) { //endtime of last meet of merge_meets
			merge_meets[merge_meets.size() - 1].ss = max(merge_meets[merge_meets.size() - 1].ss, meets.ss);
		}
		else {
			merge_meets.pb(meets);
		}
	}
	for (auto meets : merge_meets) {
		cout << meets.ff << " -> " << meets.ss << "\n";
	}
}

void reserve_s(string &s) {
	for (int i = 0; i < s.length() / 2; i++) {
		swap(s[i], s[s.length() - i - 1]);
	}
}

void reverseStringsInPlace() {
	string s;	cin >> s;
	reserve_s(s);
	cout << s << "\n";
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// meetingRanges();	//https://www.interviewcake.com/question/cpp/merging-ranges?course=fc1&section=array-and-string-manipulation
	reverseStringsInPlace();

	return 0;
}
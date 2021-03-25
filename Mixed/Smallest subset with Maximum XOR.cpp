#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;	cin >> n;
	int ar[n];	for0(i, n)	cin >> ar[i];
	int dp[n][n];	//dp[i][j] stores value of OR

	int req = 0;	for0(i, n)	req = req | ar[i];
	for0(i, n)	dp[i][i] = ar[i];

	return 0;
}
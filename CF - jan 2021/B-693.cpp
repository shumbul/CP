#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

bool subsm(int arr[], int n, int sum)
{
	int curr_sum = arr[0], start = 0, i;
	for (i = 1; i <= n; i++) {
		while (curr_sum > sum && start < i - 1) {
			curr_sum = curr_sum - arr[start];
			start++;
		}
		if (curr_sum == sum) {
			return 1;
		}
		if (i < n)
			curr_sum = curr_sum + arr[i];
	}
	return 0;
}

bool solve() {
	int n, ac = 0;	cin >> n;
	int ar[n];	for0(i, n)	{ cin >> ar[i]; ac += ar[i]; }
	// cout << ac << endl;
	if (ac % 2)	return false;
	ac /= 2;
	// cout << ac << endl;

	return subsm(ar, n, ac);
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;	cin >> t;
	while (t--) {
		if (solve())	cout << "Yes\n";
		else cout << "No\n";
	}


	return 0;
}
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
	int t;	cin >> t;
	while (t--) {
		set<int> done;
		int n;	cin >> n;
		int ar[n], maxi = -1;
		for0(i, n) cin >> ar[i];
		for0(i, n) {
			int j = i;
			int curr = 0;
			if (done.find(j) != done.end() || j >= n) continue;
			while (j < n) {
				curr += ar[j];
				j += ar[j];
				done.insert(j);
			}

			maxi = max(maxi, curr);
			// cout << ar[i] << " ";
		}
		cout << maxi << "\n";
	}

	return 0;
}
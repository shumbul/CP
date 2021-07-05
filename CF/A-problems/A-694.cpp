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
		int n;	cin >> n;
		float x; 	cin >> x;
		float ar[n];	for0(i, n)	cin >> ar[i];
		int k = accumulate(ar, ar + n, 0);
		cout << (int) (k / (int)x) << " ";
		int m = 0;
		for0(i, n)	{
			float a = ar[i] / x;
			m += ceil(a);
		}
		cout << m << "\n";
	}


	return 0;
}
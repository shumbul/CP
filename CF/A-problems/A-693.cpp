#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

bool solve(int w, int h, int n) {
	int sheets = 1;
	if (n == 1)	return 1;
	if (w % 2 && h % 2)	return 0;
	w = w * h;
	if (w % 2 == 0)	{
		while (w % 2 == 0)	{
			w = w / 2, sheets *= 2;
		}
	}
	return sheets >= n;
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int t;	cin >> t;
	while (t--) {
		int w, h, n;
		cin >> w >> h >> n;
		if (solve(w, h, n))	cout << "Yes\n";
		else cout << "No\n";
	}


	return 0;
}
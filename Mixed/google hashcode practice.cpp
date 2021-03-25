#include<bits/stdc++.h>
using namespace std;

// #define int long long
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

	int W = 1000 * 100 * 100;
	int n = 10 * 1000;
	printf("%d%d\n", W, n);
	vector<int> values;
	for (int i = 0; i < n; ++i) {
		values.pb(int(W / 10 + rand() % (W * 9LL / 10)));
	}
	random_shuffle(values.begin(), values.end());
	for (int x : values) {
		printf("%d\n", x);
	}
	puts(" ");


	return 0;
}

/*
pop_back()
rand()
random_shuffle(a.begin(), a.end())
map -> mp.upper_bound(b)
cerr<<"print\n";

*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> ar, int n) {
	if (n < 2)	return 0;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i : ar) {
		q.push(i);
	}
	int e1 , e2, ans = 0;
	while (!q.empty()) {
		if (q.size() < 2) break;
		e1 = q.top(), q.pop();
		e2 = q.top(), q.pop();
		q.push(e1 + e2);
		ans += e1 + e2;
	}
	return ans;
}

signed main() {
	int k;	cin >> k;
	vector<int> ar(k);	for (int i = 0; i < k; i++)	cin >> ar[i];
	cout << solve(ar, k) << endl;
	return 0;
}

/*
6
10 5 100 50 20 15
*/

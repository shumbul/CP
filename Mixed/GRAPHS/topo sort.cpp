//topological sort
// http://codeforces.com/problemset/gymProblem/101102/K
#include<bits/stdc++.h>
using namespace std;

int in[100001];
vi ar[100001];
vi ans(100001);
int level[100001];
void kahn(int i,int v){
	queue<int> q;
	vi vsort;
	rof(i,1,v) if(in[i]==0)	vsort.pb(i);
	vsort.sort();
	rof(i,0,vsort.size()) q.push(i);
	while(!q.empty()){
		int k=q.front();
		q.pop();
		for(int c:ar[k]){
			level[c]=level[k]+1, vsort.pb(c); in[c]--;
		}
		// in condition + vsort
		
		
		
	}
}

#define int long long
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
#define rof(i,a,b) for(int i=a;i<=b;i++)

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	int t;
	while(t--){
		int v,e;	cin>>v>>e;
		int a,b;
		rof(i,1,v)	ar[i].clear(), ans[i].clear(), in[i]=0;
		rof(i,1,e){
			cin>>a>>b;
			ar[a]=b;	in[b]++;
		}
		kahn(1,v);
		rof(i,1,v)	cout<<ans[i]<<" ";
		cout<<endl;
	}

	return 0;
}

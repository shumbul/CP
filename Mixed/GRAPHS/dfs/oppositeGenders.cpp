// SPOJ YT: Code NCode
//an application of bipartite

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
#define rof(i,a,b) for(int i=a;i<=b;i++)

vi ar[1000001];
int vis[1000001];
int col[100001];

bool color(int n, int c){
	vis[n]=1;
	if(col[n]) if(col[n]!=c) return false;
	col[n]=c;
	for(int child: ar[n]){
		if(!vis[child]) {
			vis[child]=1, col[child]=col[n]*-1;
			if(color(child, c*-1)==0) return false;
		}
		else{
			if(col[child]==col[n]) return false;
		}
	}
	return true;
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	int t;	cin>>t;
	while(t--){
		int v, e;	cin>>v>>e;
	int a,b;
	rof(i,1,e){
		cin>>a>>b;
		ar[a].pb(b), ar[b].pb(a);
	}
	cout<<color(1,-1)<<endl;
	memset(ar,0,sizeof ar);
	memset(col, 0, sizeof col);
	memset(vis,0,sizeof vis);
	}

	return 0;
}

//SPOJ - YT Code NCode
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
#define rof(i,a,b) for(int i=a;i<=b;i++)

vi ar[100001];
int vis[100001];

void dfs(int n){
	vis[n]=1;
	for(auto c: ar[n]){
		if(!vis[c]) 
		vis[c]=1, 	dfs(c);
	}
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	int v,e;	cin>>v>>e;
	if(v!=e+1) {cout<<"NO"; return 0;
	}
	int a,b;	
	rof(i,1,v-1) cin>>a>>b, ar[a].pb(b), ar[b].pb(a);
	int cc=0;
	rof(i,1,v) if(vis[i]==0) dfs(i),cc++;
	if(cc>1) {
	cout<<"No"; return 0;}
	else cout<<"Yes";
	return 0;
}
//for a graph to be tree, e=v-1, no cycle, connected
// no cycle => visited node should't come again while traversing
// connected => in 1 dfs traversal, all the nodes must be traversed!

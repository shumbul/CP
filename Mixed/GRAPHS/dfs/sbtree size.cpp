// Longest path in a tree printing
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define ff first
#define sos second
#define mod 1000000007
#define rof(i,a,b) for(int i=a;i<=b;i++)

vi ar[100001];
int vis[100001];
int ss[100001];

void dfs(int s,int par){
	
	vis[s]=1;
	for(int c:ar[s]){
		if(!vis[c]) dfs(c, s);
	}
	ss[par]=ss[par]+ss[s]+1;
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;	cin>>n;
	int a,b;
	rof(i,1,n-1){
		cin>>a>>b;
		ar[a].pb(b),ar[b].pb(a);
	}
//	rof(i,1,n) ss[i]=1;
	dfs(1,0);
	
	rof(i,1,n) cout<<i<<" -> "<<ss[i]+1<<endl;
	return 0;
}

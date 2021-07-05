// Longest path in a tree printing
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
int sec,mdis;

void dfs(int s,int dis){
	if(dis>=mdis && vis[s]==0) sec=s, mdis=dis;
	vis[s]=1;
	for(int c:ar[s]){
		if(!vis[c]) dfs(c, dis+1);
	}
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
	dfs(1,0);
	rof(i,1,n-1)	vis[i]=0;
	mdis=0;
	dfs(sec, 0);
	cout<<mdis<<endl;
	return 0;
}

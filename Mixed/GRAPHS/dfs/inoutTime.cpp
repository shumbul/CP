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
int in[100001],out[100001];
int tim=1;
void dfs(int s){
	vis[s]=1;
	in[s]=tim++;
	for(int c:ar[s]){
		if(!vis[c]) dfs(c);
	}
	out[s]=tim++;
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	int v, e;
	cin>>v>>e;
	int a,b;
	rof(i,1,e){
		cin>>a>>b;
		ar[a].pb(b), ar[b].pb(a);
	}
	dfs(3);
	rof(i,1,v){
		cout<<i<<" : "<<in[i]<<" -> "<<out[i]<<endl;
	}
	return 0;
}

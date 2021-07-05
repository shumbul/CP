//detecting cycle in a graph

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
// true=>cycle
bool dfs(int s, int par){
	vis[s]=1;
	for(int c:ar[s]){
		if(vis[c]==0) {
			if(dfs(c,s)==true) return true;
		}
		else{
			if(c!=par) return true;
		}
	}
	
	return false;
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
	cout<<dfs(1,0);
	return 0;
}

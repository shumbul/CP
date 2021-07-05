#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
#define FOR(i,a,b) for(int i=a;i<=b;i++)

vi ar[100001];
int vis[100001];

void dfs(int i){
	vis[i]=1;
	for(int c : ar[i]){
		if(!vis[c])
			dfs(c);
	}
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	int v,e,a,b;	cin>>v>>e;
	FOR(i,1,e)	cin>>a>>b, ar[a].pb(b), ar[b].pb(a);
	int connected=0;

	FOR(i,1,v){
		if(!vis[i])
		{
		connected++;
		dfs(i); 
		}
	}
	cout<<connected<<endl;
	return 0;
}

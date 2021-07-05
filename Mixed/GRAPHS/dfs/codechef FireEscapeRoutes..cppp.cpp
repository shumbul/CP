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
int cc;
void dfs(int s){
	if(vis[s]==0) cc++;
	vis[s]=1;
	for(int k:ar[s]){
		if(!vis[k]) dfs(k);
	}
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	int t;	cin>>t;
	while(t--){
		int v,e;	cin>>v>>e;
		int a,b;
		rof(i,1,e) {
			cin>>a>>b;	ar[a].pb(b), ar[b].pb(a);
		}
		int k=1,comp=0;
		rof(i,1,v){
			if(!vis[i]) {
				cc=0;
				comp++;
				dfs(i);
//				cout<<" Yo: "<<cc<<endl;
				k*=cc;
			}
		}
		cout<<comp<<" "<<k<<endl;
		rof(i,1,v) vis[i]=0, ar[i].clear();
	}

	return 0;
}

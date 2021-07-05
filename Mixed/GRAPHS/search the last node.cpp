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
int dis[100001];

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;	cin>>t;
	while(t--){
		int v,e,a,b;	cin>>v>>e;
		rof(i,1,e){
			cin>>a>>b;	ar[a].pb(b), ar[b].pb(a);
		}
		queue<int> q;
		q.push(1);
		int len=0;
		if(v==1) {cout<<0<<endl; break;}
		while(!q.empty()){
			int k=q.front();
			vis[k]=1;
			q.pop();
			for(int c:ar[k]){
				if(!vis[c]) q.push(c), vis[c]=1, dis[c]=dis[k]+1; 
				if(c==v) break;
			}
		}
		cout<<dis[v]<<endl;
		rof(i,1,v)	vis[i]=0, ar[i].clear();
	}
	

	return 0;
}

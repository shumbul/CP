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
int dist[100001];
int vis[100001];
void sscc(int source, int dis){
	if(dist[source]>dis)
	dist[source] = dis;
//	cout<<"dis "<<dis<<endl;
	for(int c: ar[source]){
		if(!vis[c]){
			vis[c]=1;
			sscc(c,dis+1);
			vis[c]=0;	//V.V.IMP
		}
	}
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int v,e;	cin>>v>>e;
//	vi ar[v+1];
//	int vis[v+1];
	int source;	cin>>source;
	int a,b;
	rof(i,1,e){
		cin>>a>>b;
		ar[a].pb(b), ar[b].pb(a);
	}
//	int dist[v+1];
	rof(i,1,v) dist[i]=INT_MAX;
	dist[source]=0;
	sscc(source,0);
	rof(i,1,v){
		cout<<source<<" -> "<<i<<" : "<<dist[i]<<endl;
	}
	return 0;
}

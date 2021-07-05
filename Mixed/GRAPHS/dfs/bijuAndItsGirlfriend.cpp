//Hackerrank - youtube Code NCode
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
	
	int v;	cin>>v;
	int a,b;	
	rof(i,1,v-1) cin>>a>>b, ar[a].pb(b), ar[b].pb(a);
	int g;	cin>>g;
	vi girls;
	rof(i,1,v) dist[i]=INT_MAX;
	dist[1]=0;
	sscc(1,0);
	rof(i,1,g)	cin>>a, girls.pb(a);
	sort(girls.begin(),girls.end(),greater<>{});
	int dis=INT_MAX;
	int choice;rof(i,1,v){
		cout<<"1"<<" -> "<<i<<" : "<<dist[i]<<endl;
	}
	for(int k:girls) if(dist[k]<=dis) dis=dist[k], choice=k;
	cout<<choice;

	return 0;
}

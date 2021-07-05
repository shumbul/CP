//some error, wrong outputs with other testcases
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
//int dis[100001];

bool bfs(int a, int b){
	queue<int> q;
	q.push(a);
	while(!q.empty()){
		int k=q.front();
		q.pop();
		vis[k]=1;
		for(int c: ar[k]){
			if(!vis[c]) q.push(c);
			if(c==b) return true;	//tru that a and b belong to the same comps
		}
	}
	return false;
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
	string c;
	rof(i,1,v)	vis[i]=0, ar[i].clear();
	vector<pair<int,int>> vp;
	rof(i,1,e){
		cin>>a>>c>>b;
		if(c=="=")	ar[a].pb(b),	ar[b].pb(a);
		else vp.pb({a,b});
	}
	int sc=0;
	rof(i,0,vp.size()){
		if(bfs(a,b)){
		sc=1;	break;
	}
	}
	if(sc==0)	cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
	return 0;
}

//using coloring technoque
// YT: CodeNCode

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
int col[100001];

bool color(int n, int c){
	vis[n]=1;
	if(col[n]) if(col[n]!=c) return false;
	col[n]=c;
	for(int child: ar[n]){
		if(!vis[child]) {
			vis[child]=1, col[child]=col[n]*-1;
			if(color(child, c*-1)==0) return false;
		}
		else{
			if(col[child]==col[n]) return false;
		}
	}
	return true;
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int v, e;	cin>>v>>e;
	int a,b;
	rof(i,1,e){
		cin>>a>>b;
		ar[a].pb(b), ar[b].pb(a);
	}
	cout<<color(1,-1);
	
	return 0;
}

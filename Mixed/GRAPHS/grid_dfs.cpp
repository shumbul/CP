// dfs in grid
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
#define rof(i,a,b) for(int i=a;i<=b;i++)

int r,c;
int grid[80][80],vis[80][80];

bool isValid(int a, int b){
	if(a<1 || b<1 || a>r || b>c || vis[a][b]) return false;
	return true;
}

void dfs(int x, int y){
	vis[x][y]=1;
	int dx[4]={ 1, 0, -1, 0};
	int dy[4]={ 0, -1, 0, 1};
	rof(i,0,3){
		if(isValid(x+dx[i], y+dy[i])) dfs(x+dx[i],y+dy[i]);
	}
	
	cout<<grid[x][y]<<"\n";
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	int n,m;	cin>>n>>m;
	r=n, c=m;
	rof(i,1,n){
		rof(j,1,m) cin>>grid[i][j];
	}
	dfs(1,1);

	return 0;
}

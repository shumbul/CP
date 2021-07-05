//similar to subset sum problem

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
#define rof(i,a,b) for(int i=a;i<=b;i++)
#define M 800

int t[M][M];

int subset_sum(int val[], int n, int w){
	rof(i,0,n-1) t[i][0]=1; // true when w=0
	
	rof(i,1,n)
		rof(j,1,w){
			if(val[i-1]<=j) //it can accomodate
				t[i][j]=t[i-1][j-val[i-1]] + t[i-1][j]; //"or" in the subset sum change to "+"
			else
				t[i][j]=t[i-1][j];	// we didn't choose this at all
		}
		return t[n][w];
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int w,val[M],n;
	cin>>n>>w;
	// t[n+1][w+1]
	rof(i,0,n-1) cin>>val[i];
	cout<<subset_sum(val,n,w)<<endl; 

	return 0;
}

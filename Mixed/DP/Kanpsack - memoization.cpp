//Aditya Verma - DP

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
#define rof(i,a,b) for(int i=a;i<=b;i++)
#define M 8000
int t[80][80];

int knapsack(int wt[],int val[], int n, int w){
	if(n==0 || w==0) return 0;
	//n and w can be memoized! as these are the only variables
	//thus, let's make a matrix for these, that  would be a 2D matrix

	if(t[n][w]!=-1) return t[n][w];
	if(wt[n-1]>w) return t[n][w]=knapsack(wt,val,n-1,w);
	
	return t[n][w]=max(val[n-1]+knapsack(wt,val,n-1,w-wt[n-1]), knapsack(wt,val,n-1,w));
	
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int wt[M],w,val[M],n;
	cin>>n>>w;
	rof(i,0,n-1) cin>>wt[i];
	rof(i,0,n-1) cin>>val[i];
	//int t[n+1][w+1];
	memset(t,-1,sizeof t);
	cout<<knapsack(wt,val,n,w)<<endl; //profit from knapsack

	return 0;
}

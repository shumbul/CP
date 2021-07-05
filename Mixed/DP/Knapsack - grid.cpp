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
int t[M][M];

void knapsack(int wt[],int val[], int n, int w){
//	if(n==0 || w==0) t[n][w]=0;
	rof(i,1,n)
	rof(j,1,n){
	if(wt[i-1]>j) t[i][j]=t[i-1][j];
	else t[i][j]= max(val[i-1]+t[j-1][j-wt[i-1]], t[i-1][j]);
}
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
	knapsack(wt,val,n,w); //profit from knapsack
	cout<<t[n][w];
	return 0;
}

/*
3 50
10 20 30
60 100 120
*/

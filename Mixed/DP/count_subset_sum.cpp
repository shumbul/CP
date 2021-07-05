//Aditya Verma - DP
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

int t[M][M],cnt;

void subset_sum(int val[], int n, int w){
	rof(i,1,w-1) t[0][1]=1;
	rof(i,0,n-1) t[i][0]=0;
	rof(i,1,n)
	rof(j,1,w){
		if(val[i-1]<=j) //it can accomodate
		t[i][j]=t[i-1][j-val[i-1]] || t[i-1][j];
		else
		t[i][j]=t[i-1][j];	// we didn't choose this at all
	}
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int w,val[M],n;
	cin>>n>>w;
	rof(i,0,n-1) cin>>val[i];
	//t[n+1][w+1];
	subset_sum(val,n,w); //profit from knapsack
	rof(i,1,n) cnt+=t[i][w];
	cout<<cnt<<endl;

	return 0;
}

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define intarr(n,arr,i)	int n,i; cin>>n; int arr[n]; for(i=0;i<n;i++) {cin>>arr[i];}
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
}

int32_t main()
{
	c_p_c();
	w(t){
		int n,i,j,xi;
		float x,avg,tavg;
		cin>>n>>xi;
		x=float(xi);
		mk(a,n,int);
		for(i=0;i<n;i++)
		cin>>a[i];
		sort(a,a+n,greater<int>());
		if(a[0]<x)
		cout<<"0"<<endl;
		else{
		avg=a[0];
		int tot=1;
		for(i=1;i<n &&avg>=x ;i++){
			tavg=((avg*(float(i))+a[i])/(i+1));
			if(tavg>=x){
			avg=tavg;
			tot++;
		}
			else break;
		}
		cout<<tot<<endl;
	}
		
	}

	return 0;
}


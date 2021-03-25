//NOTE: This code is not accepted, help me to improvise it(in the same approach) if you get the mistake!

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
		int n,k,i;	cin>>n>>k;
		int a[i],sum=0,ans=0,b[n/2],m,s,l,minians;
		for(i=0;i<n;i++)	cin>>a[i];
		
		for(i=0;i<n/2;i++)	b[i]=a[i]+a[n-i-1];
		sort(b,b+n/2);
//		for(i=0;i<n/2;i++) cout<<b[i]<<endl;
		m=ceil(n/4);
		sum=b[m];
		if(n%4==0){
		for(i=0;i<n/2;i++){
			if(a[i]+a[n-i-1]!=sum){
				if(a[i]+a[n-i-1]<sum){
					s=min(a[i],a[n-i-1]);
					if(sum-s<=k && sum-s>0) ans++;
					else ans+=2;}
				else if(a[i]+a[n-i-1]>sum){
					s=max(a[i],a[n-i-1]);
					if(s-sum<=k && s-sum>0) ans++;
					else ans+=2;
			}
			} }
			
		cout<<ans<<endl;
		}
		else{
			m=(n/4);
		sum=b[m];
		
		for(i=0;i<n/2;i++){
			if(a[i]+a[n-i-1]!=sum){
				if(a[i]+a[n-i-1]<sum){
					l=sum-a[i]+a[n-i-1];
					s=min(a[i],a[n-i-1]);
					if(l+s<=k) ans++;
					else ans+=2;}
				else if(a[i]+a[n-i-1]>sum){
					l=a[i]+a[n-i-1]-sum;
					s=max(a[i],a[n-i-1]);
					if(s-l<=k) ans++;
					else ans+=2;
			}
			} }
			m=ceil(n/4);
		sum=b[m];
		minians=ans;
		ans=0;
		for(i=0;i<n/2;i++){
			if(a[i]+a[n-i-1]!=sum){
				if(a[i]+a[n-i-1]<sum){
					l=sum-a[i]+a[n-i-1];
					s=min(a[i],a[n-i-1]);
					if(l+s<=k) ans++;
					else ans+=2;}
				else if(a[i]+a[n-i-1]>sum){
					l=a[i]+a[n-i-1]-sum;
					s=max(a[i],a[n-i-1]);
					if(s-l<=k) ans++;
					else ans+=2;
			}
			} }
			if(ans<minians)
			minians=ans;
		cout<<minians<<endl;
	}
	}
	return 0;
}


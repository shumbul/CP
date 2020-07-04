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
		intarr(n,a,i);
		sort(a,a+n);
		int cont=1,maxi=INT_MIN,k=-1,diff=1;
		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1] && a[i]==k)
			{
				k=a[i];
				cont++;
			}
			else if(a[i]==a[i-1])
			{
				cont=2;
				k=a[i];
			}
			else
			diff++;
			if(maxi<cont)
				maxi=cont;
		}
		cont=maxi;
		//last step
		maxi=min(cont,diff);
		if(cont-diff==0){
			maxi=diff-1;
		}
		if(maxi<0)
		maxi=0;
//		cout<<diff<<" "<<cont<<" ";
		cout<<maxi<<endl;
	}
	return 0;
}


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
		int a[9][9],i,j,l,m;
		string s;
		for(i=0;i<9;i++)	{
			cin>>s;
			for(j=0;j<9;j++)	{
				a[i][j]=s[j]-48;
			}
		}
//		for(i=0;i<9;i++)	{
//			for(j=0;j<9;j++)	{
//				cout<<a[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		l=m=0;
		for(i=0;i<3;i++)	{
			m=i;
			for(j=0;j<3;j++)	{
				a[l][m]=10-a[l][m];
				//cout<<a[l][m]<<" -> "<<10-a[l][m]<<endl;
				if(a[l][m]==5)
				a[l][m]=4;
				l++,m+=3;
			}
		}
		for(i=0;i<9;i++)	{
			for(j=0;j<9;j++)	{
				s[j]=a[i][j]+48;
			}
			cout<<s;
			cout<<endl;
		}
	}
	return 0;
}


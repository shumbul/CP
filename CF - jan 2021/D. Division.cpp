#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define inar(arr,n) for(int i=0; i<n; i++) cin>>arr[i];
#define suma(arr,n) for(int i=0; i<n; i++) sum+=arr[i];
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define forr(i,n) for(int i=n-1; i>=0; i--)
#define rof(i,a,b) for(int i=a;i<=b;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod=1e9+7;
ll gcd (ll a, ll b) {return ( a ? gcd(b%a, a) : b );}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
int maxN=100001;

vi pri;
bool p[100001];

void sieve(){
	for0(i,maxN)	p[i]=1;
	p[0]=p[1]=0;
	for(int i=2;i*i<maxN;i++){
		if(p[i]==1){
			for(int j=i*i;j<maxN;j+=i)	p[j]=0;
		}
	}
}

void fill(){
	for(int i=2;i<maxN;i++){
		if(p[i]==1)	pri.pb(i);
	}
}

vector<int> prime_fact(int x) {
  vector<int> primes;
  for (int i = 2; i*i <= x; ++i) {
    if (x%i == 0) { 
      while (x%i==0) {
        primes.pb(i);
        x/=i;
      }
    }
  }
  if (x != 1) {
    primes.pb(x);
  }
  sort(primes.begin(),primes.end());
  return primes;
}

int solve(int p, int q){
	if(p<q)	return p;
	vector<int> tmp=prime_fact(q);
	if(p==q)	{
		return p/(tmp[0]);
	}
	if(p%q)	return p;
	int ans=1,extra=p/q;
	for0(i,tmp.size()){
		int l=extra;
		//remove all common divisors
		while(l%tmp[i]==0)
			l/=tmp[i];
		int idk=l*q/tmp[i];
		ans=max(ans, idk);
	}
	return ans;
}

signed main(){
	
	sieve();
	fill();
	int t;	cin>>t;
	while(t--){
		int p,q;	cin>>p>>q;
		cout<<solve(p,q)<<endl;
	}
	
	return 0;
}

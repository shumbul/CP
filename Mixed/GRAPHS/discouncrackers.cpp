#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
#define rof(i,a,b) for(int i=a;i<=b;i++)

vi ar[1001];

bool check(string s1, string s2, int m){
	if(s1==s2)	return true;
	if(s1.length()!= s2.length() || m==0) return false;
	rof(i,0,s1.length()-1) {
		if(s1[i]!=s2[i]) {
			for(int k: ar[s1[i]]){
				if(k==s2[i]) continue;
				return false;
			}
		}
	}
	return true;
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	int t;	cin>>t;
		string s1,s2;
	while(t--){
		rof(i,0,100)	ar[i].clear();
		cin>>s1;
		cin>>s2;
		int m,f;	cin>>m;
		f=m;
		
		if(s1.length()!=s2.length()){		
		cout<<"Bulbul "<<s1<<"NO"<<endl; continue;
		}	
		rof(i,0,s2.length()-1) s1[i]-='a', s2[i]-='a';
//		cout<<s1<<s2<<endl;
		string rule;
		cin>>rule;
		char a,b;
		a=rule[0], b=rule[rule.length()-1];
//		cout<<a<<b<<endl;
		ar[a-'a'].pb(b-'a');
		bool res=check(s1,s2,m);
		if(res==true)	cout<<s1<<"YES"<<endl;
		else	cout<<s1<<"NO"<<endl;
	}
	
	return 0;
}

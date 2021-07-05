#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
#define rof(i,a,b) for(int i=a;i<=b;i++)

vi ar[100001];
int vis[100001];
int dis[100001];
vi pr;
bool isPrime(int n){
	
	for(int i=2;i*i<n;i++){
		if(n%i==0) return false;
	}
	return true;
}

void fillPrime(){
	rof(i,1008,9974)	if(isPrime(i)) pr.pb(i);
}	//all 4 digit prime numbers are store in pr

bool isAdj(int m, int n){
	string a=to_string(m), b=to_string(n);
	int cnt=0;
	rof(i,0,3){
		if(a[i]!=b[i]) cnt++;
		if(cnt>1) return false;
	}
	if(cnt==1) {
//		cout<<a<<" "<<b<<endl;
		return true;
	}
	return false;
	
}

void createGraph(){
	for(int i=0;i<pr.size();i++){
		for(int j=i+1;j<pr.size();j++){
			if(isAdj(pr[i],pr[j])){
				ar[pr[i]].pb(pr[j]), ar[pr[j]].pb(pr[i]);
			}
		}
	}
}

int bfs(int p1, int p2){
	queue<int> q;
	q.push(p1);
	rof(i,p1+1,p2)	dis[i]=-1;	//initially all are unreachable
	while(!q.empty()){
		int k=q.front();
		vis[k]=1;
		q.pop();
		for(int c: ar[k]){
//			cout<<k<<" -> "<<c<<endl;;
			if(!vis[c])	vis[c]=1, dis[c]=dis[k]+1, q.push(c);
			if(c==p2) return dis[c];
		}
	}
	return -1;
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	fillPrime();
	createGraph();
//	cout<<pr.size()<<endl;
	
	int t;	cin>>t;
	while(t--){
	int p1,p2;	cin>>p1>>p2;
	rof(i,p1,p2)	vis[i]=0, dis[i]=-1;
	if(p1==p2) {
		cout<<"0"<<endl;
		continue;
	}
	int d=bfs(p1,p2);
	cout<<d<<endl;
	}
	return 0;
}

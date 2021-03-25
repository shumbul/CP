#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define int long long
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
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int k,x,i;
        k=log(n+1)/log(2);
        //we now have both upper and the lower limit for k
        for(i=2;i<=k+1;i++){
        	if((int)n%(int)(pow(2,i)-1)==0 && n/(pow(2,i)-1)>=1){
        	x=n/(pow(2,i)-1);
        	if(n%x==0)
        	break;
        }
		}
        cout<<x<<endl;
    }
}

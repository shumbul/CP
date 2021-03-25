#include<bits/stdc++.h>
using namespace std;
int main()
{
     int t;
     cin>>t;
     while(t--)
     {
        int n;cin>>n;
        int a,b,i,j=0,c=0,d=0;
        for(i=0;i<n;i++) {cin>>a>>b;
        if(a<c||b<d||b-d>a-c) j=1; c=a;d=b;}
 
        if(j==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
 
     }
     return 0;
}

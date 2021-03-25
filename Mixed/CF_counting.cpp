//codeforces 
//collecting coins
#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
	return a>b?a:b;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,n,i;
		cin>>a>>b>>c>>n;
		i=max(a,max(b,c));
		
		if(i-a + i-b + i-c <=n)
		  if((n-((i-a)+i-c+i-b))%3==0)
		  {
		  	cout<<"YES\n";
		  	continue;
		  }
		  cout<<"NO\n";
	}
	return 0;
}

//cf 
//Array with odd sum
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,odd=0;
		cin>>n;
		int ar[n];
		for(i=0;i<n;i++)
		cin>>ar[i];
		for(i=0;i<n;i++)
		  if(ar[i]%2!=0)
		  {
		  	odd++;
		  }
		if(odd%2==0)
		  cout<<"NO\n";
		else
		  cout<<"YES\n";
		  
	}
	return 0;
}

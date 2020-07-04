//codeforces 
//New Year Garland
#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
	return a>b?a:b;
}
void sort(int a[])
{
	int i,j,temp;
	for (i=0;i<3;i++)
	for(j=0;j<3-i-1;j++)
	{
		if(a[j]>a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a[3],i;
		cin>>a[0]>>a[1]>>a[2];
		sort(a);
		  if(a[2]>(a[1]+a[0]+1))
		  {
		  	cout<<"No\n";
		  }
		  else
		  cout<<"Yes\n";
	}
	return 0;
}

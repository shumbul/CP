//print pattern using recusrion
#include<iostream>
using namespace std;
int j;
void upper(int n)
{
	int i;
	if(n>0)
	{
	for(i=2*n;i>=0;i-=2)
	{
		//if(i>n-i-1)
		cout<<"* ";
	}
	cout<<endl;
	upper(n-1);
    }
	else 
	return;
}

void lower(int n)
{
	int i;
	if(n<=j)
	{
	for(i=0;i<=2*n;i++)
	{
		cout<<"* ";
	}
	cout<<endl;
	lower(n+1);
    }
	else return;
}

int main()
{
	int n;
	cin>>n;
	j=n;
	upper(n);
	lower(0);
	return 0;
}

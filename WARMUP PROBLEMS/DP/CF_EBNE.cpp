//CF- #616
//A. Even But Not Even

#include<stdio.h>
void deleteplace(int a[],int j,int d)
{
	int i;
	for(i=j;i<d-1;i++)
	{
		a[j]=a[j+1];
	}
}

int makesumeven(int n, int d)
{
	    int i;
		int a[d],k=n;
		for(i=d-1;i>=0;i--)
		{
			 a[i] = k % 10;
             k /= 10;
		}
		
	    for(i=d-1;i>=0;i--)
		{
			 if(a[i]%2==1)
			 {
			 	deleteplace(a,i,d);
			 	d=d-1;
			 	break;
			 }
		}
	if(a[0]==0)
	return -1;
	n=0;
    for (i = 0; i < d; i++)
    n = 10 * n + a[i];
    return n;
}
int makeitodd(int n, int d)
{
	    int i;
		int a[d],k=n;
		for(i=d-1;i>=0;i--)
		{
			 a[i] = k % 10;
             k /= 10;
		}
		
	    deleteplace(a,d-1,d);
	    d=d-1;
	if(a[0]==0)
	return -1;
	
	int sum=0;
	for(i=d-1;i>=0;i--)
		{
			 sum+=a[i];
		}
	if(sum%2!=0)
	n=makesumeven(n,d);
	else
    {
    	n=0;
	for (i = 0; i < d; i++)
    n = 10 * n + a[i];
    }
    return n;
}

int main()
{
	int t,flag;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,d;
		scanf("%d",&d);
		scanf("%d",&n);
		
	    //if last digit even
	    if(n==-1)
	    printf("-1");
	    else
	  {
	    if(n%2==0)
		n=makeitodd(n,d);
	    if(n==-1)
	    printf("-1");
	    else
	    {
	    	int k,sum=0;
		for(i=d-1;i>=0;i--)
		{
			k=n%10;
			sum+=k;
		}
		if(sum%2!=0) //odd
		{
		n=makesumeven(n,d);
	    }
		if(n%2==0)
		n=makeitodd(n,d);
	    if(n==-1)
	    printf("-1");
	    else
	    {
	    printf("%d",n);
	    }
	    }
	    printf("\n");;
	        }
    }
	return 0;
}

/* testcase:
4
4
1227
1
0
6
177013
24
222373204424185217171912

output:
1227
-1
17703
2237344218521717191
*/

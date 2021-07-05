// Modular Exponentiation (Power in Modular Aritmetic) (x^y)
#include <iostream>
using namespace std;

int modular(int x, int y, int mod){
	if(x==1 || y==0) return 1;
	if(y%2==0){
		int k=modular(x,y/2,mod)%mod;
		return (k*k)%mod;
	}
	return ((x%mod)*(modular(x,y-1,mod)%mod))%mod;
}

int main ()
{
	long long int x,y,mod, res=1;
	cin >> x >> y >> mod;
	cout<<modular(x,y,mod)<<endl;

	return 0;
}

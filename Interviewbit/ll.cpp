#include<bits/stdc++.h>
using namespace std;

class node {
    int data;
    node *next=NULL;
    public :
	node(int d){
    	data=d;
    	cout<<"data inserted successfully"<<endl;
	}
} ;

int main()
{
	int d=5;
	node *first = new node(5);
	first=this;
	cout<<first->data;

	return 0;
}


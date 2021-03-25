#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

vector_cbegin();
void squareVectorInPlace(vector<int>& intVector);
vector<int> squareVectorOutOfPlace(const vector<int>& intVector);
void array_slicing();
void ARRAYS();

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ARRAYS();

	return 0;
}

void ARRAYS() {
	// 1
	array_slicing();
	//2
	vi intVector = {1, 4, 2, 3, 7, 2, 5, 8, 3, 7, 3};
	squareVectorInPlace(intVector);
	vi newVector = squareVectorOutOfPlace(intVector);
	cout << "\nsquareVectorOutOfPlace returned the following vector:\n";
	for (auto element : newVector) {
		cout << element << " ";
	}
	cout << "\n";
	// 3
	vector_cbegin();
}


void array_slicing() {
	// create a sliced vector from another vector
	vi myVector = {1, 4, 2, 3, 7, 2, 5, 8, 3, 7, 3};
	int startIndex = 3, endIndex = 6;
	// enindex is exlcuded
	vector<int> sliced_vector(myVector.begin() + startIndex, myVector.begin() + endIndex);
	cout << "Sliced vector\n";
	for (auto element : sliced_vector) {
		cout << element << " ";
		cout << "\nmyVector: \n";
		for (auto element : myVector) {
			cout << element << " ";
		}

		cout << "\nmyVector slicing while traversing :\n";
		// Time -  O(n)
		// whoops, I just spent O(n) time and space!
		for (int item : vector<int>(myVector.begin() + 1, myVector.end())) {
			cout << item << " ";
		}
	}
}

void squareVectorInPlace(vector<int>& intVector)
{
	for (size_t i = 0; i < intVector.size(); ++i) {
		intVector[i] *= intVector[i];
	}


	// NOTE: no need to return anything - we modified
	// intVector in place
}

vector<int> squareVectorOutOfPlace(const vector<int>& intVector)
{
	// we create a new vector with the size of the input vector
	vector<int> squaredVector(intVector.size());

	for (size_t i = 0; i < intVector.size(); ++i) {
		int item = intVector[i];
		squaredVector[i] =  item * item;
	}

	return squaredVector;
}

vector_cbegin() {

}

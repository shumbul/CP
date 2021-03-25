#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <map> 
#include <iterator> 
using namespace std;

int main() {
    int n;
string name;
long num;
cin >> n;
map <string, long> pBook;
for (int i = 0; i < n; i++) {
    cin >> name;
    cin >> num;
    pBook[name] = num;
}
while(cin >> name) {
    if (pBook.find(name) != pBook.end()) {
        cout << name << "=" << pBook.find(name)->second << endl;
    } else {
        cout << "Not found" << endl;
    }
}
}

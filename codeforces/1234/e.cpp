#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

int main() {
	int n, m;
	cin >> m >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	for(int i = 1; i < n; ++i) v[i] = v[i] + v[i-1];
	for(int i = 1; i <= m; ++i) {
		int r = 0;
		if(i >=2) r += (v[i-2]);
		if((n-i-1) >= 0) r+= (n-i-1);//(v[n-1]-v[i]);
		r += (2*i -1);
		cout << r << " ";
	}
	cout << endl;
}




  //i 1 2 3 ... i - 1 i + 1 i + 2
//p 1 2 3 4     i     i+1   i+2

//(1,2) 1
//(2,3) 1
//(i-2, i-1) 1
//(i-1,i) = i - 1
//(i, i+1) = i
//(i+1, i+2) = 1
//(i+2, i+3) = 1

//(i-2) + (n - i -1) + (i-1) + (i)
//f(i,n) = 4i + n - 4
//f(1,4) = 2 + 4 - 4 = 3
//f(2,4) = 4 + 4 - 4 = 4
//f(3,4) = 6 + 4 - 4 = 6
//f(4,4) 

//i + 1 ... n-1

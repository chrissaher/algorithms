#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

int main() {
	int q;
	cin >> q;
	while(q--) {
		int n, aux;
		cin >> n;
		double sum = 0;
		for(int i = 0; i < n; ++i) {
			cin >> aux;
			sum += aux;
		}
		cout << ll(ceil(sum / n)) << endl;
	}
}

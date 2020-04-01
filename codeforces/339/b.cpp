#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

int main() {
	int n, m;
	cin >> n >> m;
	ll cost = 0;
	int prev = 1;
	for(int i = 0; i < m; ++i) {
		int curr;
		cin >> curr;
		ll c1 = curr - prev;
		if(c1 < 0) c1 = n + c1;
		cost += c1;
		prev = curr;
	}
	cout << cost << endl;
	return 0;
}

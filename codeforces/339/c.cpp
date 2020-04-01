#include <bits/stdc++.h>
using namespace std;
string s;
int m;
bool solve(vector<int>&route, int i, int j, int k, int cl, int cr) {
	if(i == m) {
		route.push_back(j);
		return true;
	}
	for(int c = 1; c <= 10; ++c) {
		if(c != j && s[c-1] == '1') {
			int ncl = cl, ncr = cr;
			if(k == 0) {
				ncl += c;
				if(ncl <= ncr) continue;
			}
			else {
				ncr += c;
				if(ncr <= ncl) continue;
			}
			
			route.push_back(j);
			bool ans = solve(route, i+1, c, 1-k, ncl, ncr);
			if(ans) return true;
			route.pop_back();
		}
	}
	return false;
}

int main() {
	cin >> s;
	cin >> m;
	vector<int> route;
	bool ans = solve(route, 0, -1, 0, 0,0);
	if(ans) {
		cout << "YES" << endl;
		for(int i = 1; i < int(route.size()); ++i)
			cout << route[i] << " ";
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}

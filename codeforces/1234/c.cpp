#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

int main() {
	int q, n;
	string s1, s2;
	cin >> q;
	while(q--) {
		cin >> n;
		cin >> s1;
		cin >> s2;
		bool valid = true;
		bool up = true;
		for(int i = 0; i < n; ++i) {
			int c1 = int(s1[i]-'0');
			int c2 = int(s2[i]-'0');
			if(up) {
				if(c1 == 1 || c1 == 2) continue;
				else if(c2 != 1 && c2 != 2) {
					up = false;
					continue;
				} else {
					valid = false;
					break;
				}
			} else {
				if(c2 == 1 || c2 == 2) continue;
				else if(c1 != 1 && c1 != 2) {
					up = true;
					continue;
				} else {
					valid = false;
					break;
				}
			}
		}
		if(valid && up == false) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n, s, k;
		cin >> n >> s >> k;
		vector<int> ks(k);
		for(int i = 0; i < k; ++i) cin >> ks[i];
		sort(ks.begin(), ks.end());
		int p = -1;
		for(int i = 0; i < k; ++i) {
			if(ks[i] == s) {
				p = i;
				break;
			}
		}
		if(p == -1) {
			cout << 0 << endl;
			continue;
		}
		int cost = INT_MAX;
		for(int i = 0; i < k; ++i) {
			if(ks[i] < s) {
				int cc1 = ks[i]-1;
				if(cc1 < 1) continue; 
				if(i > 0 && ks[i-1] == cc1) continue;
				cost = min(cost, s - cc1);
			} else if(ks[i] > s) {
				int cc2 = ks[i] + 1;
				if(cc2 > n) continue;
				if(i + 1 < k && ks[i+1] == cc2) continue;
				cost = min(cost, cc2 - s);
			} else {
				int cc1 = ks[i]-1;
				if(!(cc1 < 1) && !(i > 0 && ks[i-1] == cc1))
					cost = min(cost, s - cc1);
				int cc2 = ks[i] + 1;
				if(!(cc2 > n) && !(i + 1 < k && ks[i+1] == cc2))
					cost = min(cost, cc2 - s);
			}
		}
		cout << cost << endl;
		
	}
	return 0;
}

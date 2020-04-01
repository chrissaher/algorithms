#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

list<int> dq;
map<int, list<int>::iterator> mapa;
int main() {
	int n, k, t;
	cin >> n >> k;
	
	for(int i = 0; i < n; ++i) {
		cin >> t;
		if(mapa.find(t) != mapa.end()) continue;
		else {
			if(dq.size() == k) {
				int last = dq.back();
				dq.pop_back();
				mapa.erase(last);
			}
			dq.push_front(t);
			mapa[t] = dq.begin();
		}
	}
	cout << dq.size() << endl;
	for(int x: dq) cout << x << " ";
	cout << endl;
	return 0;

}

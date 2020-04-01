#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;

int st[2*M];
int n,q;
void build() {
	memset(st, 0, sizeof(st));
}

void update(int p, int v) {
	p +=n;
	if(st[p] == v) return;
	for(st[p]=v; p > 1; p>>=1) st[p>>1] = st[p] + st[p^1];
}

int query(int l, int r) {
	int res = 0;
	for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
		if(l&1) res += st[l++];
		if(r&1) res += st[--r];
	}
	return res;
}

int memo[2][M];

bool check(int c, int r) {
	bool unblocked = false;
	if(r==0) {
		if(memo[c][r] == 0) {
			if(memo[1-c][r] == 0 && memo[1-c][r+1] == 0) {
				unblocked = true;
			}
			if(memo[1-c][r] == 0 && memo[c][r+1] == 0) {
				unblocked = true;
			}
			if(memo[c][r+1] == 0) {
				unblocked = true;
			}
			if(memo[1-c][r] == 0 && memo[1-c][r+1] == 0) {
				unblocked = true;
			}
		}
		return unblocked;
	}
	if(r == (n-1)) {
		if(memo[c][r] == 0) {
			if(memo[1-c][r] == 0 && memo[c][r-1] == 0) {
				unblocked = true;
			}
			if(memo[1-c][r] == 0 && memo[1-c][r-1] == 0) {
				unblocked = true;
			}
			if(memo[c][r-1] == 0) {
				unblocked = true;
			}
			if(memo[1-c][r-1] == 0 && memo[1-c][r] == 0) {
				unblocked = true;
			}
		}
		return unblocked;
	}
	if(memo[c][r] == 0) {
		if(memo[1-c][r] == 0 && memo[c][r-1] == 0 && memo[1-c][r+1] == 0) {
			unblocked = true;
		}
		if(memo[1-c][r] == 0 && memo[1-c][r-1] == 0 && memo[c][r+1] == 0) {
			unblocked = true;
		}
		if(memo[c][r-1] == 0 && memo[c][r+1] == 0) {
			unblocked = true;
		}
		if(memo[1-c][r-1] == 0 && memo[1-c][r] == 0 && memo[1-c][r+1] == 0) {
			unblocked = true;
		}
	}
	return unblocked;
}

int main() {
	cin >> n >> q;
	n++;
	build();
	memset(memo, 0, sizeof(memo));
	memo[1][0] = 1;
	memo[0][n] = 1;

	while(q--) {
		int c,r;
		cin >> c >> r;
		c--;
		
		memo[c][r] = 1 - memo[c][r];

		 
		if(memo[c][r] == 0) {
			if(check(c, r)) update(r, 0);
			if(check(c, r-1) || check(1-c, r-1)) update(r-1, 0);
			if(check(c, r+1) || check(1-c, r+1)) update(r+1, 0);
		} else {
			if(memo[1-c][r-1] == 1 || memo[1-c][r] == 1 || memo[1-c][r+1] == 1) {
				update(r, 1);
			}
		}
		
		
		if(query(0, n+2)==0)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}

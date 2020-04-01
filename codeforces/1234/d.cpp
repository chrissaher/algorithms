#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
const int MAXN = 2*M;
int st[MAXN];
int n;

int combine(int l, int r) {
	return l | r;
}

int encode(char c) {
	int idx = int(c - 'a');
	return (1 << idx);
}

void build(string s) {
	n = s.size();
	for(int i = 0; i < n; ++i) {
		st[n + i] = encode(s[i]);
	}
	for(int p = n-1; p > 0; --p) st[p] = combine(st[p<<1], st[p<<1|1]);
}

void update(int p, char c) {
	for(st[p+=n] = encode(c); p > 1; p>>=1) st[p>>1] = combine(st[p], st[p^1]);
}

int query(int l, int r) {
	int res = 0;
	for(l += n, r += n; l < r; l>>=1, r>>=1) {
		if(l&1) res = combine(res, st[l++]);
		if(r&1) res = combine(st[--r], res);
	}
	return __builtin_popcount(res);
}

int main() {
	string s;
	cin >> s;
	build(s);
	int q, type, l, r;
	char c;
	cin >> q;
	while(q--) {
		cin >> type;
		if(type == 1) {
			cin >> l >> c;
			l--;
			update(l, c);
		} else {
			cin >> l >> r;
			l--;
			cout << query(l, r) << endl;
		}
	}
	return 0;
}

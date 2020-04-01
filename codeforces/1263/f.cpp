#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 1;
const int MAXN = 2 * M;
int sta[MAXN], stb[MAXN], stc[MAXN];
int n;

void build() {
	memset(sta, 0, sizeof(sta));
	memset(stb, 0, sizeof(stb));
	memset(stc, 0, sizeof(stc));
}

void update(int p, char c) {
	p += M;
	if(c == '(') stb[p] = 1;
	else stc[p] = 1;
	for (; p > 1; p >>= 1) {
		int l = (p&1)?p^1:p, r = (p&1)?p:p^1;
		int t = min(stb[l], stc[r]);
		sta[p>>1] = sta[l] + sta[r] + 2 * t;
		stb[p>>1] = stb[l] + stb[r] - t;
		stc[p>>1] = stc[l] + stc[r] - t;
	}
}

void combine(int a[], int b[], bool shift) {
	int t = min(a[1],b[2]);
	if(shift) t = min(a[2], b[1]);
	a[0] = a[0] + b[0] + 2*t;
	a[1] = a[1] + b[1] - t;
	a[2] = a[2] + b[2] - t;
}

int query(int l, int r) {  // sum on interval [l, r)
	int resl[3]={0,0,0}, resr[3]={0,0,0};
	for (l += M, r += M; l < r; l >>= 1, r >>= 1) {
		if (l&1) {
			int aux[] = {sta[l], stb[l], stc[l]};
			combine(resl, aux, false);
			l++;
		}
		if (r&1) {
			--r;
			int aux[] = {sta[r], stb[r], stc[r]};
			combine(resr, aux, true);
		}
	}
	combine(resl, resr, false);
	return resl[0];
}

int main() {
	string s;
	cin >> s;
	n = s.length();
	build();
	for(int i = 0; i < n; ++i) {
		update(i, s[i]);
	}
	int q, l, r;
	cin >> q;
	while(q--) {
		cin >> l >> r;
		l--;
		cout << query(l,r) << endl;
	}
	return 0;
}

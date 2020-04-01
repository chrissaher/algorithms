#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000009;
const int M = 300005;
const int MAXN = 2*M;

struct node {
	int k;
};

int st[MAXN], d[M];
int n, m, h;

const int sqrt5=383008016;
int q1,q2,inv;
int p1[M], p2[M], f1[M], f2[M];

int sum(int a, int b) {
	return (a + b) % MOD;
}

void apply(int p, int value) {
	st[p] += value;
	if (p < n) d[p] += value;
}

void calc(int p, int k) {
	if (d[p] == 0) st[p] = sum(st[p<<1], st[p<<1|1]);
	else st[p] = (d[p] * k )% MOD;
}

void apply(int p, int value, int k) {
	st[p] += value * k;
	if (p < n) d[p] += value;
}

void build(int l, int r) {
	int k = 2;
	for (l += n, r += n-1; l > 1; k <<= 1) {
		l >>= 1, r >>= 1;
		for (int i = r; i >= l; --i)
			calc(i, k);
	}
}

void push(int l, int r) {
	int s = h, k = 1 << (h-1);
	for (l += n, r += n-1; s > 0; --s, k >>= 1)
		for (int i = l >> s; i <= r >> s; ++i)
			if (d[i] != 0) {
				apply(i<<1, d[i], k);
				apply(i<<1|1, d[i], k);
				d[i] = 0;
			}
}

void modify(int l, int r, int value) {
	if (value == 0) return;
	push(l, l + 1);
	push(r - 1, r);
	int l0 = l, r0 = r, k = 1;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
		if (l&1) apply(l++, value, k);
		if (r&1) apply(--r, value, k);
	}
	build(l0, l0 + 1);
	build(r0 - 1, r0);
}

int query(int l, int r) {
	push(l, l + 1);
	push(r - 1, r);
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = sum(res, st[l++]);
		if (r&1) res = sum(res, st[--r]);
	}
	return res;
}

typedef long long ll;
ll modpow(ll x,int y){
	LL res=1;
	for(;y;y>>=1,(x*=x)%=MOD)
		if(y&1)(res*=x)%=MOD;
	return res;
}

void init() {
	inv=modpow(sqrt5,MOD-2);
	q1=(sqrt5+1LL)*modpow(2,MOD-2)%MOD;
	q2=(MOD+1LL-sqrt5)*modpow(2,MOD-2)%MOD;
	p1[0] = 1; p2[0] = 1;
	for(int i = 1; i < M; ++i) {
		p1[i] = ll(p1[i-1]* q1) % MOD;
		p2[i] = ll(p2[i-1]* q2) % MOD;
	}
	f1[1] = 1; f2[1] = 1;
	for(int i = 2; i < M; ++i) {
		f1[i] = sum(p1[i-1], f1[i-1]);
		f2[i] = sum(p2[i-1], f2[i-1]);
	}
}

int main() {
	init();
	cin >> n >> m;
	h = sizeof(int) * 8 - __builtin_clz(n);
	memset(d, 0, sizeof(d));
	for(int i = 0; i < n; ++i) cin >> st[i + n];
	build(); 
	int t, l, r;
	for(int i = 0; i < m; ++i) {
		cin >> t >> l >> r;
		if(t == 1) modify(l, r, 4);
		else cout << query(l, r) << endl;
	}
	return 0;
}

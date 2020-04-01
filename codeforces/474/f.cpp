#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e5 + 100;
const int MAXN = 2*M;
int n;

ll gcd(ll a, ll b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

struct node {
	int cont;
	ll mcd;
	node(int x) {
		cont = 1;
		mcd = x;
	}
	node(int x, ll v) {
		cont = x;
		mcd = v;
	}
	node() {
		cont = 0;
		mcd = 0;
	}
};

node st[MAXN];

node combine(node a, node b) {
	if(a.mcd == 0 || b.mcd == 0) return node();
	int cont = 0;
	ll mcd = gcd(a.mcd, b.mcd);
	if(mcd % a.mcd == 0) cont += a.cont;
	if(mcd % b.mcd == 0) cont += b.cont;
	return node(cont, mcd);
}

void build() {
	for(int p = n-1; p > 0; --p) st[p] = combine(st[p<<1], st[p<<1|1]);
}

node query(int l, int r) {
	node res;
	bool first = true;
	for(l+=n, r+=n; l<r; l>>=1,r>>=1) {
		if(l&1) {
			if(first) res = st[l++];
			else res = combine(res, st[l++]);
			first = false;
		}
		if(r&1) {
			if(first) res = st[--r];
			else res = combine(st[--r], res);
			first = false;
		}
	}
	return res;
}

int main() {
	cin >> n;
	ll aux;
	for(int i = 0; i < n; ++i) {
		cin >> aux;
		st[i + n] = node(aux);
	}
	build();
	int q, l, r;
	cin >> q;
	while(q--) {
		cin >> l >> r;
		l--;
		node res = query(l, r);
		cout << (r-l) - res.cont << endl;
	}
	return 0;
}

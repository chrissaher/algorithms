#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1<<18) + 10;
int st[MAXN];
int n, k;

bool oper(int h) {
	if(k % 2 != 0) {
		if(h % 2 == 0) return false;// xor
		else return true;
	} else {
		if(h % 2 == 0) return true;
		else return false; // xor
	}
	return true; // or
}

int combine(int l, int r) {
	int h = log2(l);
	if(oper(h)) return st[l] | st[r];
	else return st[l] ^ st[r];
}

void modify(int p, int v) {
	for(st[p += n] = v; p>>=1;) st[p] = combine((p<<1), (p<<1|1));
}

int main() {
	int q, aux;
	cin >> k >> q;
	memset(st, 0, sizeof(st));
	n = (1<<k);
	for(int i = 0; i < n; ++i) {
		cin >> aux;
		modify(i, aux);
	}
	int p, v;
	for(int i = 0; i < q; ++i) {
		cin >> p >> v;
		modify(--p, v);
		cout << st[1] << endl;
	}
	return 0;
}

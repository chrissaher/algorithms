#include <bits/stdc++.h>
using namespace std;
 
const int M = 1e6 + 5;
const int MAXN = 2*M;
const int INF = 2*M;
 
struct node {
	int sum;
	int maxp;
	int minp;
	node() {
		sum = 0;
		maxp = -INF;
		minp = INF;
	}
};
 
node st[MAXN];
int n;
 
int val(char c) {
	if(c == '(') return 1;
	if(c == ')') return -1;
	return 0;
}
 
node combine(node &a, node &b) {
	node r;
	r.sum = a.sum + b.sum;
	r.maxp = max(a.maxp, a.sum + b.maxp);
	r.minp = min(a.minp, a.sum + b.minp);
	return r;
}
 
void update(int p, int value) {
	p += n;
	st[p].sum = st[p].maxp = st[p].minp = value;
	for(; p >>= 1;) st[p] = combine(st[p<<1], st[p<<1|1]);
}
 
node query(int l, int r)  {
	node resl, resr;
	for(l += n, r += n; l < r; l>>=1, r>>=1) {
		if(l&1) resl = combine(resl, st[l++]);
		if(r&1) resr = combine(st[--r], resr);
	}
	return combine(resl, resr);
}
 
 
int main(){
	cin >> n;
	string s;
	cin >> s;
	int it = 0;
	int last = 0;
	for(char c: s) {
		if(c == 'L') {
			it = max(it-1, 0);
			cout << last << " ";
		} else if(c == 'R') {
			it++;
			cout << last << " ";
		} else {
			update(it, val(c));
			node res = query(0, n);
			if(res.sum == 0 && res.minp >= 0) last = res.maxp;
			else last = -1;
			cout << last << " ";
		}
	}
	cout << endl;
	return 0;
}

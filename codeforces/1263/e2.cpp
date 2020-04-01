#include <bits/stdc++.h>
using namespace std;

const int M = 1048576;
const int MAXN = 2*M + 100;
const long long INF = 33554432;
long long st[2*MAXN], stmax[MAXN], stmin[MAXN];
int n;

long long mymax(long long a, long long b) {
	if(a > b) return a;
	return b;
}

long long mymin(long long a, long long b) {
	if(a > b) return b;
	return a;
}

void build() {
	for(int i = 2*n+1; i > 0; i--){
		st[i] = 0;
		stmax[i] = -INF;
		stmin[i] = INF;
	}
	stmax[1]=0;
	stmin[1]=0;
}

void update(int p, int value) {
	p += M;
	st[p] = stmax[p] = stmin[p] = value;
	for (; p > 1; p >>= 1) {
		int l = (p&1)?p^1:p, r = (p&1)?p:p^1;
		st[p>>1] = st[l] + st[r];
		stmax[p>>1] = mymax(stmax[l], st[l] + stmax[r]);
		stmin[p>>1] = mymin(stmin[l], st[l] + stmin[r]);
	}
}


int main() {
	cin >> n;
	string s;
	cin >> s;
	int it = 0;
	build();
	for(char c: s) {
		if(c == 'L') {
			if(it > 0) it--;
		} else if(c == 'R') {
			it++;
		} else if(c == '(') {
			update(it, 1);
		} else if(c == ')') {
			update(it, -1);
		} else {
			update(it, 0);
		}
		if(st[1] == 0 && stmin[1] >= 0) cout << stmax[1] << " ";
		else cout << "-1 ";
	}
	cout << endl;
	return 0;
}

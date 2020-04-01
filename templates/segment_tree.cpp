/*
 * Useful links:
 * - https://codeforces.com/blog/entry/18051
 * - https://github.com/jiezhou0731/programming/blob/master/codeforces/603div2E.cpp
 * - algorithm book page 91
 * 
 * Problems tested:
 * - https://codeforces.com/contest/1263/problem/E
 * - https://codeforces.com/contest/380/problem/C
 * - https://codeforces.com/problemset/problem/339/D
 * - https://codeforces.com/contest/474/problem/F
 * 
 * Tricks:
 * - Remember it is possible to force the tree have a power of 2 leaves 
 *   by adding a very large value. (Usually, half of the segment tree 
 *   size works).
 * - Query operations of type [l, r) are easier to code. [l,r] are
 *   easier to explain.
 * 
 * Pending:
 * - Revisit max prefix sum from : 
 *   https://www.geeksforgeeks.org/maximum-prefix-sum-given-range/
 * - Add lazy propagation
 * 
 * Notes:
 * - Using 1-index arrays.
 * */

#include <bits/stdc++.h>
using namespace std;


const int N = 1e5;  // limit for array size
int n;  // array size
int st[2 * N]; // s

/* 
 * Basic segment tree
 * */
 
void build() {
	for (int i = n - 1; i > 0; --i) st[i] = st[i<<1] + st[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
	for (st[p += n] = value; p > 1; p >>= 1) st[p>>1] = st[p] + st[p^1];
}

void modify(int p, int value) {
	for(st[p += n] = v; p>>=1;) st[p] = st[p<<1] + st[p<<1|1];
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res += st[l++];
		if (r&1) res += st[--r];
	}
	return res;
}


int query_include(int l, int r) {  // sum on interval [l, r]
	int res = 0;
	for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
		if (l&1) res += st[l++];
		if (!(r&1)) res += st[r--];
	}
	return res;
}

/* 
 * For special cases whem combining left and right is not only a
 * single operation
 * */


void modify(int p, int value) { // special cases
	for(st[p+=n] = value; p>>=1; ) st[p] = combine(st[p<<1], st[p<<1|1]);
}

node query(int l, int r) { // interval is [l, r)
	node rl, rr;
	for(l += n, r += n; l < r; l>>=1, r>>=1) {
		if(l&1) rl = combine(rl, st[l++]);
		if(r&1) rr = combine(st[--r], rr);
	}
	return combine(rl, rr);
}

int main() {
  scanf("%d", &n);
  int aux = 0;
  for (int i = 0; i < n; ++i) {
	  scanf("%d", &aux);
	  t[n + i] = aux;
	  tree[n + i] = aux;
  }
  build();
  modify(0, 8);
  return 0;
}

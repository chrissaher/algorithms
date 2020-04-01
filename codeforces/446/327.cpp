#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	const int N = 1e5;
	int n;
	int st[2 * N];
	int dp1[2*N], dp2[2*N];
	void update(int p) {
		for(p += n; p > 1; p>>=1) st[p>>1] = st[p] + st[p^1];
	}
	int query(int l, int r) {
		int res = 0;
		for(l +=n, r+=n; l < r; l>>=1, r>>=1) {
			if(l&1) res += st[l++];
			if(r&1) res += st[--r];
		}
		return res;
	}
	
	void dfs(int p, int lo, int hi) {
		
	}
	
    int countRangeSum(vector<int>& nums, int lower, int upper) {
		n = nums.size();
		for(int i = 0; i < n; ++i) {
			st[i+n] = nums[i];
			update(i);
		}
		
        
    }
};

int main() {
	int n, lo, hi;
	cin >> n >> lo >> hi;
	vector<int> nums(n);
	for(int i = 0; i < n; ++i) cin >> nums[i];
	cout << countRangeSum(nums, lower, upper) << endl;
	return 0;
}

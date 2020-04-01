#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int lo = 1, hi = n, mid;
        vector<int> res;
        res.push_back(0);
        int k = n;
        while(k > 1) {
            lo = 1;
            hi = n;
            int div = n / k;
            res.push_back(div);
            for(int i = 0; i < 50; ++i) {
                mid = (lo + hi) >> 1;
                int dd = n / mid;
                if(dd > div) lo = mid + 1;
                else hi = mid;
            }
            k = lo - 1;
        }
        res.push_back(n);
        cout << res.size() << endl;
        for(int i = 0; i < int(res.size()); ++i) {
            if(i > 0) cout << " ";
            cout << res[i];
        }
        cout << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int gen(vector<int> &v, int pos, int k) {
    int num = 0;
    for(int i = 3; i >=0; --i) {
        int j = v[i];
        num *= 10;
        if(i == pos) { j = (j + k) % 10;}
        num += j;
    }
    return num;
}
int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> v(n);
        map<int,int> pins;
        for(int i =0; i < n; ++i) {
            cin >> v[i];
            pins[v[i]]++;
        }
        vector<int> res;
        int cont = 0;
        for(auto p: v) {
            if(pins[p] == 1) {
                // cout << p << endl;
                res.push_back(p);
            }else {
                int c  = p;
                vector<int> dd;
                while(c > 0) {
                    dd.push_back(c % 10);
                    c /= 10;
                }
                while(dd.size() != 4) dd.push_back(0);
                bool found = false;
                for(int i = 0; i < 4; ++i) {
                    for(int j = 1; j<= 9; ++j)
                    {
                        int pos = gen(dd, i, j);
                        if(pins.find(pos) == pins.end()) {
                            pins[p]--;
                            pins[pos]++;
                            // cout << pos << endl;
                            cont ++;
                            res.push_back(pos);
                            found = true;
                            break;
                        }
                    }
                    if(found) break;
                }
            }
        }
        cout << cont << endl;
        for(auto v: res) printf("%04d\n", v);
    }
}

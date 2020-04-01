#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int toint(char c) {
    return int(c - 'a');
}

int findSet(vector<int> &p, int i) {
    if(p[i] == i) return i;
    return p[i] = findSet(p, p[i]);
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    string aux;
    for(int i = 0; i < n; ++i) {
        cin >> aux;
        v[i] = aux;
    }
    vector<int> parent(30);
    for(int i = 0; i < 30; ++i) parent[i] = i;

    vector<bool> exist(30, false);
    for(string s: v) {
        int k = s.length();
        exist[toint(s[0])] = true;
        for(int j = 1; j < k; ++j) {
            int idx = toint(s[j]);
            exist[idx] = true;
            parent[findSet(parent, idx)] = parent[findSet(parent, toint(s[0]))];
        }
    }

    set<ll> diff;
    for(int i = 0; i < 30; ++i) {
        if(!exist[i]) continue;
        findSet(parent, i);
        diff.insert(parent[i]);
    }
    cout << diff.size() << endl;
    return 0;
}

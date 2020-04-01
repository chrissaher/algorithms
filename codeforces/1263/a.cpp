#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    while(n--) {
        vector<int> v(3);
        cin >> v[0];
        cin >> v[1];
        cin >> v[2];
        sort(v.begin(), v.end());
        if(v[2] <= v[0] + v[1]) cout << (v[0] + v[1] + v[2]) / 2 << endl;
        else cout << v[0] + v[1] << endl;
    }
}

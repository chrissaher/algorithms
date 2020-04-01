#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

int main() {
	string s;
	cin >> s;
	char cad[int(s.size()) + 1];
	strcpy(cad, s.c_str());
	char *pch = strtok(cad, "+");
	vector<int> v;
	while(pch != NULL) {
		v.push_back(atoi(pch));
		pch = strtok(NULL, "+");
	}
	sort(v.begin(), v.end());
	string res = "";
	for(int i = 0; i < int(v.size()); ++i) {
		if(i > 0) res += "+";
		res += to_string(v[i]);
	}
	cout << res << endl;
	return 0;
}

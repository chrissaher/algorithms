#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	double k=0;
	for(double i = 1; i <= n; ++i) k += (1.0/ i);
	printf("%.012lf\n", k);
	return 0;
}

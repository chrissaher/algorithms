#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

stack<int> sleft, sright, minl, maxl, minr, maxr;
int openl = 0, openr = 0;

void pop_sleft() {
	if(sleft.size() == 0) return;
	int c = sleft.top();
	sleft.pop();
	openl -= c;
	minl.pop();
	maxl.pop();
}

void pop_sright() {
	if(sright.size() == 0) return;
	int c = sright.top();
	sright.pop();
	openr -= c;
	minr.pop();
	maxr.pop();
}

void push_sleft(int x) {
	sleft.push(x);
	openl += x;
	int topmin = INT_MAX, topmax = INT_MIN;
	if(minl.size() > 0) topmin = minl.top();
	if(maxl.size() > 0) topmax = maxl.top();
	minl.push(min(topmin, openl));
	maxl.push(max(topmax, openl));
}

void push_sright(int x) {
	sright.push(x);
	openr += x;
	int topmin = INT_MAX, topmax = INT_MIN;
	if(minr.size() > 0) topmin = minr.top();
	if(maxr.size() > 0) topmax = maxr.top();
	minr.push(min(topmin, openr));
	maxr.push(max(topmax, openr));
}

bool is_sleft_correct() {
	if(minl.size() == 0 || minl.top() >= 0) return true;
	return false;
}

bool is_sright_correct() {
	if(minr.size() == 0 || minr.top() >= 0) return true;
	return false;
}

int depth_sleft() {
	if(sleft.size() > 0) return maxl.top();
	return 0;
}

int depth_sright() {
	if(sright.size() > 0) return maxr.top();
	return 0;
}

int main() {
	int n;
	cin >> n;
	string cad;
	cin >> cad;
	int it = 0;
	for (int i = 0; i < n; i++) {
        push_sright(0);
    }
    push_sleft(0);
	for(char c: cad) {
		if(c == 'L') {
			if(it > 0) {
				it--;
				push_sright(-sleft.top());
				pop_sleft();
			}			
		} else if(c == 'R') {
			it = it + 1;
			push_sleft(-sright.top());
			pop_sright();
			
		} else if(c == '(') {
			pop_sleft();
			push_sleft(1);
		} else if(c == ')') {
			pop_sleft();
			push_sleft(-1);
		} else {
			pop_sleft();
			push_sleft(0);
		}
		if(is_sleft_correct() && is_sright_correct() && openl == openr) {
			cout << max(max(depth_sleft(), depth_sright()), openl) << " ";
		} else {
			cout << "-1 ";
		}
	}
	cout << endl;
	return 0;
}

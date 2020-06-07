#include<iostream>
#include<vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n; 
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];	
		vector<int> good(2, 0);
		int flag = 1;
		for (int i = 0; i < n; ++i) {
			if (a[i] > b[i] && !good[0]) {
				flag = 0;
			}
			else if (a[i] < b[i] && !good[1]) {
				flag = 0;
			}
			if (a[i] == -1) good[0] = 1;
			if (a[i] == 1) good[1] = 1;
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
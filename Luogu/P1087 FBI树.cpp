#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
string tmp;
void getPost(int l,int r) {
	if (l<r) {
		bool is0, is1;
		is0 = is1 = false;
		for (int i = l; i <= r; i++) {
			if (tmp[i] == '0')is0 = true;
			if (tmp[i] == '1')is1 = true;
			if (is0&&is1)break;
		}
		int mid = (l+r) / 2;
		getPost(l, mid);
		getPost(mid+1, r);
		if (is0&&is1) cout << "F";
		else if (is0) cout << "B";
		else if (is1) cout << "I";
	}
	else if (l == r) {
		if(tmp[l]=='1')cout << "I";
		else cout << 'B';
	}

}
int main() {
	tmp.resize(2000);
	cin.sync_with_stdio(false);
	cin >> n;
	cin >> tmp;
	getPost(0,tmp.size()-1);
	return 0;
}
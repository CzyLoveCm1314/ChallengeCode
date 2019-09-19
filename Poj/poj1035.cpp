#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

const int maxn = 10010;
string dic[maxn];

int main(){
	int cnt = 0;
	while (cin >> dic[cnt]) {
		if (dic[cnt][0] == '#')break;
		cnt++;
	}
	string temp;
	while (cin >> temp) {
		if (temp[0] == '#')break;
		int f = 0;
		for (int i = 0; i < cnt&&!f; i++) {
			int tlen = temp.size();
			int dlen = dic[i].size();
			if (temp == dic[i]) {
				cout << temp << " is correct\n";
				f = 1;
				break;
			}
		}
		if (f == 0) {
			cout << temp << ':';
			for (int i = 0; i < cnt; i++) {
				int tlen = temp.size();
				int dlen = dic[i].size();
				if (tlen == dlen) {
					int flag = 0;
					int j = 0;
					int k = 0;
					while (k < dlen) {
						if (temp[j] == dic[i][k]) {
							j++;
							k++;
						}
						else {
							k++;
							j++;
							flag++;
						}
					}
					if (flag == 1 && j == tlen) {
						cout <<  ' ' << dic[i];
					}
				}
				else if (tlen - dlen == -1) {
					int flag = 0;
					int j = 0;
					int k = 0;
					while (k < dlen) {
						if (temp[j] == dic[i][k]) {
							j++;
							k++;
						}
						else {
							k++;
							flag++;
						}
					}
					if (flag == 1 && j == tlen) {
						cout <<  ' ' << dic[i];
					}
				}
				else if (tlen - dlen == 1) {
					int flag = 0;
					int j = 0;
					int k = 0;
					while (j < tlen) {
						if (temp[j] == dic[i][k]) {
							j++;
							k++;
						}
						else {
							j++;
							flag++;
						}
					}
					if (flag == 1 && k == dlen) {
						cout << ' ' << dic[i];
					}
				}
			}
			printf("\n");
		}
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int m, n, k, l, d, xx1, xx2, yy1, yy2;
int C[2000], R[2000];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	scanf("%d%d%d%d%d", &m, &n, &k, &l, &d);
	for (int i = 1; i <= d; i++) {
		scanf("%d%d%d%d", &xx1, &yy1, &xx2, &yy2);
		if (xx1 == xx2) {
			if (yy1 > yy2)swap(yy1, yy2);
			C[yy1]++;
		}
		else {
			if (xx1 > xx2)swap(xx1, xx2);
			R[xx1]++;
		}
	}
	vector<int> a1, a2;
	while (k--) {
		int cnt;
		int mm  = -1;
		for (int i = 1; i < m; i++) {
			if (R[i] > mm) {
				mm = R[i];
				cnt = i;
			}
		}
		a1.push_back(cnt);
		R[cnt] = 0;
	}
	while (l--) {
		int cnt ;
		int mm= -1;
		for (int i = 1; i < n; i++) {
			if (C[i] > mm) {
				mm = C[i];
				cnt = i;
			}
		}
		a2.push_back(cnt); 
		C[cnt] = 0;
		
	}
	sort(a1.begin(), a1.end());
	for (int i = 0; i < a1.size(); i++) {
		if (i == 0) printf("%d", a1[0]);
		else printf(" %d", a1[i]);
	}
	printf("\n");
	sort(a2.begin(), a2.end());
	for (int i = 0; i < a2.size(); i++) {
		if (i == 0) printf("%d", a2[0]);
		else printf(" %d", a2[i]);
	}
	printf("\n");
	return 0;
}
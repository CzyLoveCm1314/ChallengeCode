#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int a[300];

int main() {
	int n;
	scanf("%d", &n);
	int t;
	for (int i = n; i >=0; i--) 
		scanf("%d", &a[i]);
	bool flag = false;
	int i = n;
	while (a[i] == 0)i--;
	for (; i >= 0; i--) {
		if (a[i] == 0)continue;
		if (!flag) {
			if (i != 0) {
				if (a[i] == 1) {
					if (i == 1)printf("x", i);
					else printf("x^%d", i);
				}
				else if (a[i] == -1) {
					if (i == 1)printf("-x", i);
					else printf("-x^%d", i);
				}
				else if (a[i] > 0) {
					if (i == 1) printf("%dx", a[i]);
					else printf("%dx^%d", a[i], i);
				}
				else {
					if (i == 1) printf("%dx", a[i]);
					else printf("%dx^%d", a[i], i);
				}
			}
			else if (i == 0) printf("%d", a[i]);
			flag = true;
		}
		else {
			if (i != 0) {
				if (a[i] == 1) {
					if (i == 1)printf("+x", i);
					else printf("+x^%d", i);
				}
				else if (a[i] == -1) {
					if (i == 1)printf("-x", i);
					else printf("-x^%d", i);
				}
				else if (a[i] > 0) {
					if(i==1) printf("+%dx", a[i]);
					else printf("+%dx^%d", a[i], i);
				}
				else {
					if (i == 1) printf("%dx", a[i]);
					else printf("%dx^%d", a[i], i);
				}
			}
			else if (i == 0) {
				if(a[i]>0) printf("+%d", a[i]);
				else  printf("%d", a[i]);
			}
		}
	}
	return 0;
}
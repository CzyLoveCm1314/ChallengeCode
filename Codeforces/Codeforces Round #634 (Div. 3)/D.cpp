#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

const int maxn = 12;
int a[maxn][maxn];
char s[maxn];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 9; i++) {
			scanf("%s", s);
			for (int j = 0; j < 10; j++) {
				a[i][j] = s[j] - '0';
			}
		}
		int vis[11] = { 0 };
		int x[][2] = { {0,0},{1,3},{2,6},{3,1},{4,4},{5,7},{6,2},{7,5},{8,8} };
		for (int i = 0; i < 9; i++) {
			if (a[x[i][0]][x[i][1]] == 1) a[x[i][0]][x[i][1]] = 2;
			else a[x[i][0]][x[i][1]] = 1;
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) printf("%d", a[i][j]);
			printf("\n");
		}
	}

	return 0;
}
/*
2
916853247
543627918
728941653
659472831
481539726
372186594
865394172
294718365
137265489
154873296
386592714
729641835
863725149
975314628
412968357
631457982
598236471
247189563
*/
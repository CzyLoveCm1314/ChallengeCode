
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

char chess[20][40];
char s1[100];
char s2[100];
char s[100];

void solve(char s[], int flag) {
	int x, y;
	int len = strlen(s); 
	for (int i = 0; i < len;){
		if (s[i] >= 'A' && s[i] <= 'Z'){
			x = 2 * (s[i + 2] - '0') - 1;
			y = 4 * (s[i + 1] - 'a' + 1) - 2;
			if (flag) chess[x][y] = s[i];
			else chess[x][y] = s[i] + 32;
			i += 4;
		}
		else if (s[i] >= 'a' && s[i] <= 'z'){
			x = 2 * (s[i + 1] - '0') - 1;
			y = 4 * (s[i] - 'a' + 1) - 2;
			if (flag) chess[x][y] = 'P';
			else chess[x][y] = 'p';
			i += 3;
		}
	}
}

int main()
{
	while (scanf("%s%s", s, s1) != EOF) {
		scanf("%s%s", s, s2);
		int flag1 = 1;
		int flag2 = 1;
		for (int i = 0; i <= 16; i++) {
			if (i % 2 == 0) {
				for (int j = 0; j <= 32; j++) {
					if (j % 4 == 0) chess[i][j] = '+';
					else chess[i][j] = '-';
				}
			}
			else if (i % 2 == 1) {
				for (int j = 0; j <= 32; j += 4) {
					if (j % 4 == 0) {
						chess[i][j] = '|';
						if (flag1 == 1) {
							chess[i][j + 1] = ':';
							chess[i][j + 3] = ':';
						}
						else if (flag1 == 0) {
							chess[i][j + 1] = '.';
							chess[i][j + 3] = '.';
						}
						flag1 = !flag1;
						if (flag2 == 1) {
							chess[i][j + 2] = ':';
						}
						else if (flag2 == 0) {
							chess[i][j + 2] = '.';
						}
						flag2 = !flag2;
					}
				}
			}
		}

		if (s[0] == 'W') {
			solve(s1, 0);
			solve(s2, 1);
		}
		else {
			solve(s1, 1);
			solve(s2, 0);
		}
		for (int i = 16; i >= 0; i--) {
			for (int j = 0; j <= 32; j++)
				printf("%c", chess[i][j]);
			printf("\n");
		}
	}
	return 0;
}

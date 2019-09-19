#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

#define maxn 50
char map[maxn][maxn];
char str[maxn];
struct chess {
	char attr;
	int x;
	char y;
}white[maxn],black[maxn];
int bcnt, wcnt;

int main() {
	bcnt = wcnt = 0;
	for (int i = 0; i < 17; i++) {
		scanf("%s", str);
		for (int j = 0; j < 33; j++) map[i][j] = str[j];
	}
	printf("White: ");
	for (int i = 15; i >= 1; i -= 2)
		for (int j = 2; j <= 30; j += 4)
			if (map[i][j] == 'K')
				printf("K%c%d", 'a' + j / 4, 8 - i / 2);
	for (int i = 15; i >= 1; i -= 2)
		for (int j = 2; j <= 30; j += 4)
			if (map[i][j] == 'Q')
				printf(",Q%c%d", 'a' + j / 4, 8 - i / 2);
	for (int i = 15; i >= 1; i -= 2)
		for (int j = 2; j <= 30; j += 4)
			if (map[i][j] == 'R')
				printf(",R%c%d", 'a' + j / 4, 8 - i / 2);
	for (int i = 15; i >= 1; i -= 2)
		for (int j = 2; j <= 30; j += 4)
			if (map[i][j] == 'B')
				printf(",B%c%d", 'a' + j / 4, 8 - i / 2);
	for (int i = 15; i >= 1; i -= 2)
		for (int j = 2; j <= 30; j += 4)
			if (map[i][j] == 'N')
				printf(",N%c%d", 'a' + j / 4, 8 - i / 2);
	for (int i = 15; i >= 1; i -= 2)
		for (int j = 2; j <= 30; j += 4)
			if (map[i][j] == 'P')
				printf(",%c%d", 'a' + j / 4, 8 - i / 2);
	printf("\n");

	printf("Black: ");
	for (int i = 1; i <= 15; i += 2)
		for (int j = 2; j <= 30; j += 4)
			if (map[i][j] == 'k')
				printf("K%c%d", 'a' + j / 4, 8 - i / 2);
	for (int i = 1; i <= 15; i += 2)
		for (int j = 2; j <= 30; j += 4)
			if (map[i][j] == 'q')
				printf(",Q%c%d", 'a' + j / 4, 8 - i / 2);
	for (int i = 1; i <= 15; i += 2)
		for (int j = 2; j <= 30; j += 4)
			if (map[i][j] == 'r')
				printf(",R%c%d", 'a' + j / 4, 8 - i / 2);
	for (int i = 1; i <= 15; i += 2)
		for (int j = 2; j <= 30; j += 4)
			if (map[i][j] == 'b')
				printf(",B%c%d", 'a' + j / 4, 8 - i / 2);
	for (int i = 1; i <= 15; i += 2)
		for (int j = 2; j <= 30; j += 4)
			if (map[i][j] == 'n')
				printf(",N%c%d", 'a' + j / 4, 8 - i / 2);
	for (int i = 1; i <= 15; i += 2)
		for (int j = 2; j <= 30; j += 4)
			if (map[i][j] == 'p')
				printf(",%c%d", 'a' + j / 4, 8 - i / 2);
	printf("\n");
	return 0;
}
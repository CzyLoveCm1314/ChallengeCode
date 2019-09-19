#include<cstdio>
#include<cstring>
#include<vector>

const int maxn = 1000010;
char s1[maxn], s2[maxn];
int next[maxn];
int ans[maxn];
int cnt;

void getNext(char* s) {
	int slen = strlen(s);
	int j = -1;
	next[0] = -1;
	for (int i = 1; i < slen; i++) {
		while (j != -1 && s[i] != s[j + 1]) j = next[j];
		if (s[i] == s[j + 1]) j++;
		next[i] = j;
	}
}
void KMP(char* s, char* t) {
	int slen = strlen(s);
	int tlen = strlen(t);
	getNext(s);
	cnt = 0;
	int j = -1;
	for (int i = 0; i < tlen; i++) {
		while (j != -1 && t[i] != s[j + 1]) j = next[j];
		if (t[i] == s[j + 1]) j++;
		if (j == slen - 1) {
			ans[cnt++] = i;
		}
	}
}
int main() {
	scanf("%s", s1);
	scanf("%s", s2);
	KMP(s2,s1);
	int len = strlen(s2);
	for (int i = 0; i < cnt; i++) printf("%d\n", ans[i]-len+2);
	for (int i = 0; i < len; i++) {
		if (i == 0) printf("%d", next[i]+1);
		else printf(" %d", next[i]+1);
	}
	printf("\n");
	return 0;
}
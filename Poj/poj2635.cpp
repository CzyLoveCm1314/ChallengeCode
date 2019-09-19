#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

const int maxn = 1e6 + 1000;
int kt[10010];
int len;
int prime[maxn];
bool vis[maxn]; 

int Prime(int n)
{
	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i<n; i++){
		if (!vis[i]) prime[cnt++] = i;
		for (int j = 0; j<cnt&&i*prime[j]<n; j++) {
			vis[i*prime[j]] = 1;
			if (i%prime[j] == 0) break;
		}
	}
	return cnt; 
}

bool mod(int *K, int p, int len){
	int sq = 0;
	for (int i = len - 1; i >= 0; i--)
		sq = (sq * 1000 + K[i]) % p;
	if (!sq) return false;
	return true;
}

int main() {
	int pnum = Prime(maxn);
	char K[10010];
	int L;
	while (~scanf("%s %d", K, &L) && K[0] && L) {
		memset(kt, 0, sizeof(kt));
		int lenk = strlen(K);
		for (int i = 0; i < lenk; i++) {
			int pKt = (lenk + 2 - i) / 3 - 1;
			kt[pKt] = kt[pKt] * 10 + (K[i] - '0');
		}
		int lenKt = (lenk + 2) / 3;
		bool flag = true;
		int pMin = 0;
		while (prime[pMin]<L){
			if (!mod(kt, prime[pMin], lenKt)){
				flag = false;
				printf("BAD %d\n", prime[pMin]);
				break;
			}
			pMin++;
		}
		if (flag) printf("GOOD\n");
	}
	return 0;
}
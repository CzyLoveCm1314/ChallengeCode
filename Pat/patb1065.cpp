#include<stdio.h>
#include<string.h>
int guest[100000][2], single[100000];

int main(){
	int n, m, i, j, t;
	memset(guest, -1, sizeof(guest));
	scanf("%d", &n);
	while (n--){
		scanf("%d%d", &i, &j);
		guest[i][0] = j;
		guest[j][0] = i;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &t);
		guest[t][1] = 1;
	}
	int ans = 0;
	int cnt = 0;
	for (i = 0; i < 100000; i++) {
		if (guest[i][1] == 1) {
			if (guest[i][0]!=-1 && guest[guest[i][0]][1] == 1)continue;
			else {
				ans++;
				single[cnt++] = i;
			}
		}
	}
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++){
		if (i == cnt - 1) printf("%.5d", single[i]);
		else printf("%.5d ", single[i]);
	}
	return 0;
}


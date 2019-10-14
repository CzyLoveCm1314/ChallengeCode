#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
using namespace std;

const int MAXN = 10000;
const int INF = 0x3f3f3f3f;
int num[MAXN];
int color[MAXN];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF){
		int Max = -INF;
		memset(color, -1, sizeof(color));
		for (int i = 0; i < n; i++){
			int x, y, c;
			scanf("%d%d%d", &x, &y, &c);
			Max = max(Max, c);
			for (int j = x; j < y; j++)
				color[j] = c;
		}
		memset(num, 0, sizeof(num));
		for (int i = 0; i <= 8000; ){
			int temp = color[i];
			if (temp == -1){
				i++;
				continue;
			}
			i++;
			while (temp == color[i])
				i++;
			num[temp]++;
		}
		for (int i = 0; i <= Max; i++)
			if (num[i])
				printf("%d %d\n", i, num[i]);
		printf("\n");
	}
	return 0;
}

#include<cstdio>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	int n, m;
	while (t--) {
		scanf("%d%d", &n, &m);
		if (n % 2 == 1 && m % 2 == 1) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if ((i + j) % 2 == 0)printf("B");
					else printf("W");
				}
				printf("\n");
			}
		}
		else if (n % 2 == 1 && m % 2 == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (i == n - 2 && j == 0) printf("B");
					else if ((i + j) % 2 == 0)printf("B");
					else printf("W");
				}
				printf("\n");
			}
		}
		else if (n % 2 == 0 && m % 2 == 1) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (i == n - 1 && j == m-1) printf("B");
					else if ((i + j) % 2 == 0)printf("B");
					else printf("W");
				}
				printf("\n");
			}
		}
		else if (n % 2 == 0 && m % 2 == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (i == n - 2 && j == 1) printf("B");
					else if ((i + j) % 2 == 0)printf("B");
					else printf("W");
				}
				printf("\n");
			}
		}
	}
	return 0;
}
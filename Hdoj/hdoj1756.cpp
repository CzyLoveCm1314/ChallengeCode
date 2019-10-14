#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int maxn = 1100;
const double eps = 1e-8;
int n;
struct point {
	double x, y;
}p[maxn];

double cross(point p0, point p1, point p2) {
	return (p1.x - p0.x)*(p2.y - p0.y) - (p1.y - p0.y)*(p2.x - p0.x);
}
int dcmp(double x) {
	if (fabs(x) < eps) return 0;
	return x<0 ? -1 : 1;
}

int main() {
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) scanf("%d%d", &p[i].x, &p[i].y);
		p[n] = p[0];
		int t;
		scanf("%d", &t);
		while (t--) {
			double now;
			int flag = 1;
			point temp;
			scanf("%d%d", &temp.x, &temp.y);
			for (int i = 0; i < n; i++) {
				now = cross(temp, p[i], p[i + 1]);
				cout << now << endl;
				if (now < 0) {
					flag = 0;
					break;
				}
			}
			if (flag)printf("Yes\n");
			else printf("No\n");
		}

	}
	return 0;
}
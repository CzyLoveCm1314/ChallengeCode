#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

#define maxn 45
int w, h;
int map[maxn][maxn];
int vis[maxn][maxn];
int lstep,rstep;
struct node {
	int x, y;
	int dec;
}s,e;

void dfsleft(node s, node e) {
	lstep++;
	if (s.x == e.x&&s.y == e.y) {
		return ;
	}
	node next;
	if (s.dec ==0) {
		if (s.y - 1 >= 0 && map[s.x][s.y - 1] != '#') {
			next = s;
			next.y--;
			next.dec = 1;
			dfsleft(next, e);
		}
		else if (s.x - 1 >= 0 && map[s.x - 1][s.y] != '#') {
			next = s;
			next.x--;
			next.dec = 0;
			dfsleft(next, e);
		}
		else if (s.y + 1 < w && map[s.x][s.y + 1] != '#') {
			next = s;
			next.y++;
			next.dec = 3;
			dfsleft(next, e);
		}
		else if (s.x + 1 < w && map[s.x + 1][s.y] != '#') {
			next = s;
			next.x++;
			next.dec = 2;
			dfsleft(next, e);
		}
	}
	else if (s.dec == 1) {
		if (s.x + 1 < w && map[s.x + 1][s.y] != '#') {
			next = s;
			next.x++;
			next.dec = 2;
			dfsleft(next, e);
		}
		else if (s.y - 1 >= 0 && map[s.x][s.y - 1] != '#') {
			next = s;
			next.y--;
			next.dec = 1;
			dfsleft(next, e);
		}
		else if (s.x - 1 >= 0 && map[s.x - 1][s.y] != '#') {
			next = s;
			next.x--;
			next.dec = 0;
			dfsleft(next, e);
		}
		else if (s.y + 1 < w && map[s.x][s.y + 1] != '#') {
			next = s;
			next.y++;
			next.dec = 3;
			dfsleft(next, e);
		}
	}
	else if (s.dec == 2) {
		if (s.y + 1 < w && map[s.x][s.y + 1] != '#') {
			next = s;
			next.y++;
			next.dec = 3;
			dfsleft(next, e);
		}
		else if (s.x + 1 < w && map[s.x + 1][s.y] != '#') {
			next = s;
			next.x++;
			next.dec = 2;
			dfsleft(next, e);
		}
		else if (s.y - 1 >= 0 && map[s.x][s.y - 1] != '#') {
			next = s;
			next.y--;
			next.dec = 1;
			dfsleft(next, e);
		}
		else if (s.x - 1 >= 0 && map[s.x - 1][s.y] != '#') {
			next = s;
			next.x--;
			next.dec = 0;
			dfsleft(next, e);
		}
	}
	else if (s.dec == 3) {
		if (s.x - 1 >= 0 && map[s.x - 1][s.y] != '#') {
			next = s;
			next.x--;
			next.dec = 0;
			dfsleft(next, e);
		}
		else if (s.y + 1 < w && map[s.x][s.y + 1] != '#') {
			next = s;
			next.y++;
			next.dec = 3;
			dfsleft(next, e);
		}
		else if (s.x + 1 < w && map[s.x + 1][s.y] != '#') {
			next = s;
			next.x++;
			next.dec = 2;
			dfsleft(next, e);
		}
		else if (s.y - 1 >= 0 && map[s.x][s.y - 1] != '#') {
			next = s;
			next.y--;
			next.dec = 1;
			dfsleft(next, e);
		}
	}
	return;
}

void dfsright(node s, node e) {
	rstep++;
	if (s.x == e.x&&s.y == e.y) return;
	node next;
	if (s.dec == 0) {
		if (s.y + 1 < w && map[s.x][s.y + 1] != '#') {
			next = s;
			next.y++;
			next.dec = 3;
			dfsright(next, e);
		}
		else if (s.x - 1 >= 0 && map[s.x - 1][s.y] != '#') {
			next = s;
			next.x--;
			next.dec = 0;
			dfsright(next, e);
		}
		else if (s.y - 1 >= 0 && map[s.x][s.y - 1] != '#') {
			next = s;
			next.y--;
			next.dec = 1;
			dfsright(next, e);
		}
		else if (s.x + 1 < w && map[s.x + 1][s.y] != '#') {
			next = s;
			next.x++;
			next.dec = 2;
			dfsright(next, e);
		}
	}
	else if (s.dec == 1) {
		if (s.x - 1 >= 0 && map[s.x - 1][s.y] != '#') {
			next = s;
			next.x--;
			next.dec = 0;
			dfsright(next, e);
		}
		else if (s.y - 1 >= 0 && map[s.x][s.y - 1] != '#') {
			next = s;
			next.y--;
			next.dec = 1;
			dfsright(next, e);
		}
		else if (s.x + 1 < w && map[s.x + 1][s.y] != '#') {
			next = s;
			next.x++;
			next.dec = 2;
			dfsright(next, e);
		}
		else if (s.y + 1 < w && map[s.x][s.y + 1] != '#') {
			next = s;
			next.y++;
			next.dec = 3;
			dfsright(next, e);
		}
	}
	else if (s.dec == 2) {
		if (s.y - 1 >= 0 && map[s.x][s.y - 1] != '#') {
			next = s;
			next.y--;
			next.dec = 1;
			dfsright(next, e);
		}
		else if (s.x + 1 < w && map[s.x + 1][s.y] != '#') {
			next = s;
			next.x++;
			next.dec = 2;
			dfsright(next, e);
		}
		else if (s.y + 1 < w && map[s.x][s.y + 1] != '#') {
			next = s;
			next.y++;
			next.dec = 3;
			dfsright(next, e);
		}
		else if (s.x - 1 >= 0 && map[s.x - 1][s.y] != '#') {
			next = s;
			next.x--;
			next.dec = 0;
			dfsright(next, e);
		}
	}
		else if (s.dec == 3) {
		if (s.x + 1 < w && map[s.x + 1][s.y] != '#') {
			next = s;
			next.x++;
			next.dec = 2;
			dfsright(next, e);
		}
		else if (s.y + 1 < w && map[s.x][s.y + 1] != '#') {
			next = s;
			next.y++;
			next.dec = 3;
			dfsright(next, e);
		}
		else if (s.x - 1 >= 0 && map[s.x - 1][s.y] != '#') {
			next = s;
			next.x--;
			next.dec = 0;
			dfsright(next, e);
		}
		else if (s.y - 1 >= 0 && map[s.x][s.y - 1] != '#') {
			next = s;
			next.y--;
			next.dec = 1;
			dfsright(next, e);
		}
	}
	return;
}

int bfsmin(node s, node e) {
	queue<node> q;
	q.push(s);
	memset(vis, 0, sizeof(vis));
	vis[s.x][s.y] = 1;
	while (!q.empty()) {
		node head = q.front();
		if (head.x == e.x&&head.y == e.y) return vis[head.x][head.y];
		node next;
		q.pop();
		if (head.x + 1 < h&&!vis[head.x + 1][head.y]&& map[head.x + 1][head.y]!='#') {
			next = head;
			next.x++;
			q.push(next);
			vis[head.x + 1][head.y] = vis[head.x][head.y] + 1;
		}
		if (head.x - 1 >= 0 && !vis[head.x - 1][head.y]&& map[head.x - 1][head.y] != '#') {
			next = head;
			next.x--;
			q.push(next);
			vis[head.x - 1][head.y] = vis[head.x][head.y] + 1;
		}
		if (head.y - 1 >= 0&& !vis[head.x][head.y - 1]&& map[head.x ][head.y- 1] != '#') {
			next = head;
			next.y--;
			q.push(next);
			vis[head.x ][head.y- 1] = vis[head.x][head.y] + 1;
		}
		if (head.y + 1 < w && !vis[head.x][head.y + 1] && map[head.x][head.y + 1] != '#') {
			next = head;
			next.y++;
			q.push(next);
			vis[head.x][head.y + 1] = vis[head.x][head.y] + 1;
		}
	}
	return 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		lstep = rstep = 0;
		char op[maxn];
		memset(map, 0, sizeof(map));
		scanf("%d%d", &w, &h);
		for (int i = 0; i < h; i++) {
			scanf("%s", op);
			for (int j = 0; j < w; j++) {
				map[i][j] = op[j];
				if (map[i][j] == 'S') {
					s.x = i;
					s.y = j;
					s.dec = 1;
				}
				if (map[i][j] == 'E') {
					e.x = i;
					e.y = j;
				}
			}
		}
		dfsleft(s, e);
		dfsright(s, e);
		cout <<lstep<<' '<<rstep<<' '<< bfsmin(s, e) << endl;
	}

	return 0;
}
#include <vector>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
#define N 110
#define M 3645
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const double PI = acos(-1);
#define fi first
#define se second
#define L o<<1
#define R o<<1|1
#define tl tree[o].l
#define tr tree[o].r
#define tw tree[o].w
#define to tree[o].ok
#define rep(i, lll, nnn) for(int i = (lll); i <= (nnn); i++)

int n, m;
int sx, sy, ex, ey;
char maze[N][N];
struct Node {
	int x, y, o, d;
	Node(int a, int b, int c, int e) :x(a), y(b), o(c), d(e) {}
	bool operator < (const Node & t) const {
		return d > t.d;
	}
};
struct node {
	int a, b, c, d;
	node(int a, int b, int c, int e) :a(a), b(b), c(c), d(e) {}
	bool operator < (const node & t) const {
		if (t.d == d) {
			if (t.b == b) {
				if (c == t.c) {
					return a > t.a;
				}
				return c > t.c;
			}
			return b > t.b;
		}
		return d > t.d;
	}
};
priority_queue<Node, vector<Node> > que;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
map<node, bool> mp;
int maxo[N][N], mind[N][N];

int bfs()
{
	mp.clear();
	while (!que.empty()) que.pop();
	memset(maxo, -1, sizeof maxo);
	memset(mind, INF, sizeof mind);

	que.push(Node(sx, sy, 0, 0));
	mp[node(sx, sy, 0, 0)] = true;
	maxo[sx][sy] = mind[sx][sy] = 0;
	int x, y, xx, yy;

	// int ans = INF;
	while (!que.empty()) {
		Node h = que.top(); que.pop();
		x = h.x; y = h.y;
		if (x == ex && y == ey) return h.d;
		//cout << x <<  ' ' << y << ' ' << h.o << ' ' << h.d;
		//cout << "mp " << mp[Node(0, 1, 2, 3)] << endl;
		rep(i, 0, 3) {
			xx = x + dx[i]; yy = y + dy[i];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			//if(x == 0 && y == 0 && xx == 0 && yy == 1 && h.o == 1) cout << "zzzzzz" << endl;
			if (maze[xx][yy] == '.' || maze[xx][yy] == 'S' || maze[xx][yy] == 'T') {
				if (!mp[node(xx, yy, h.o, h.d + 1)]) {
					if (maxo[xx][yy] >= h.o && mind[xx][yy] <= h.d + 1) continue;
					maxo[xx][yy] = max(maxo[xx][yy], h.o);
					mind[xx][yy] = min(mind[xx][yy], h.d + 1);
					mp[node(xx, yy, h.o, h.d + 1)] = true;
					//  cout << ".. " << xx<< ' ' << yy<< ' ' <<h.o<<' ' << h.d + 1 <<endl;
					que.push(Node(xx, yy, h.o, h.d + 1));
				}
			}
			else if (maze[xx][yy] == '#') {
				if (h.o == 0) continue;
				if (!mp[node(xx, yy, h.o - 1, h.d + 2)]) {
					if (maxo[xx][yy] >= h.o - 1 && mind[xx][yy] <= h.d + 2) continue;
					maxo[xx][yy] = max(maxo[xx][yy], h.o - 1);
					mind[xx][yy] = min(mind[xx][yy], h.d + 2);
					mp[node(xx, yy, h.o - 1, h.d + 2)] = true;
					//cout << "## " << xx<< ' ' << yy<< ' ' <<h.o - 1<<' ' << h.d + 2 <<endl;
					que.push(Node(xx, yy, h.o - 1, h.d + 2));
				}
			}
			else if (maze[xx][yy] == 'B') {
				if (h.o == 5) {
					if (!mp[node(xx, yy, h.o, h.d + 1)]) {
						if (maxo[xx][yy] >= h.o && mind[xx][yy] <= h.d + 1) continue;
						mp[node(xx, yy, h.o, h.d + 1)] = true;//cout << "BB " << xx<< ' ' << yy<< ' ' <<h.o + 1<<' ' << h.d + 1 <<endl;
						maxo[xx][yy] = max(maxo[xx][yy], h.o);
						mind[xx][yy] = min(mind[xx][yy], h.d + 1);
						que.push(Node(xx, yy, h.o, h.d + 1));
					}
				}
				else {//if(xx == 0 && yy == 1)cout << "mp "  <<mp[Node(0, 1, 2, 3)] << endl;
					  //cout << "xx  " << ' ' <<xx << ' ' << yy << ' ' << h.o + 1<< ' ' << ' ' << h.d + 1 << ' ' << mp[Node(xx, yy, h.o + 1, h.d + 1)] << endl;
					if (!mp[node(xx, yy, h.o + 1, h.d + 1)]) {//cout << "sasa" << endl;
						if (maxo[xx][yy] >= h.o + 1 && mind[xx][yy] <= h.d + 1) continue;
						mp[node(xx, yy, h.o + 1, h.d + 1)] = true;//cout << "BB " << xx<< ' ' << yy<< ' ' <<h.o + 1<<' ' << h.d + 1 <<endl;
						maxo[xx][yy] = max(maxo[xx][yy], h.o + 1);
						mind[xx][yy] = min(mind[xx][yy], h.d + 1);
						que.push(Node(xx, yy, h.o + 1, h.d + 1));
					}
				}
			}
			else {
				if (!mp[node(xx, yy, h.o, h.d)]) {
					if (maxo[xx][yy] >= h.o && mind[xx][yy] <= h.d) continue;
					mp[node(xx, yy, h.o, h.d)] = true;//cout << "PP " << xx<< ' ' << yy<< ' ' <<h.o<<' ' << h.d <<endl;
					maxo[xx][yy] = max(maxo[xx][yy], h.o);
					mind[xx][yy] = min(mind[xx][yy], h.d);
					que.push(Node(xx, yy, h.o, h.d));
				}
			}
			// if(xx == 0 && yy == 1)cout << "mp "  <<mp[node(0, 1, 2, 3)] << endl;
		}
	}

	return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
#endif

	while (~scanf("%d%d", &n, &m) && n + m) {
		rep(i, 0, n - 1) scanf("%s", maze[i]);
		rep(i, 0, n - 1) rep(j, 0, m - 1) {
			if (maze[i][j] == 'S') {
				sx = i; sy = j;
			}
			if (maze[i][j] == 'T') {
				ex = i; ey = j;
			}
		}
		mp.clear();
		printf("%d\n", bfs());
	}

	return 0;
}
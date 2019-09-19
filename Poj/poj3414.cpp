#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 110;
int a;
int b;
int aim;

struct Node {
	int l;
	int r;
	int step;
	Node(int l = 0, int r = 0, int step = 0) {
		this->l = l;
		this->r = r;
		this->step = step;
	}
};
struct Path {
	int l;
	int r;
	int method;
	Path(int l = 0, int r = 0, int method = 0) {
		this->l = l;
		this->r = r;
		this->method = method;
	}
};
queue<Node> q;
Path visit[MAX + 2][MAX + 2];
const char act[][10] = { "", "FILL(1)", "FILL(2)","DROP(1)","DROP(2)","POUR(1,2)", "POUR(2,1)" };

void _print(int l, int r) {
	if (!l && !r)
		return;
	_print(visit[l][r].l, visit[l][r].r);
	printf("\n%s", act[visit[l][r].method]);
}
void bfs()
{
	Node head;
	q.push(Node{ 0, 0, 0 });
	visit[0][0] = Path{ 0, 0, -1 };
	while (!q.empty())
	{
		head = q.front();
		q.pop();
		if (head.l == aim || head.r == aim) {
			printf("%d", head.step);
			_print(head.l, head.r);
			return;
		}
		//  fill    1
		if (head.l < a && !visit[a][head.r].method) {
			q.push(Node{ a, head.r, head.step + 1 });
			visit[a][head.r] = Path{ head.l, head.r, 1 };
		}
		//  fill    2
		if (head.r < b && !visit[head.l][b].method) {
			q.push(Node{ head.l, b, head.step + 1 });
			visit[head.l][b] = Path{ head.l, head.r, 2 };
		}
		//  drop    1
		if (head.l && !visit[0][head.r].method) {
			q.push(Node{ 0, head.r, head.step + 1 });
			visit[0][head.r] = Path{ head.l, head.r, 3 };
		}
		//  drop    2
		if (head.r && !visit[head.l][0].method) {
			q.push(Node{ head.l, 0, head.step + 1 });
			visit[head.l][0] = Path{ head.l, head.r, 4 };
		}
		//  pour    1   to   2
		if (head.l >= b - head.r) {
			if (!visit[head.l - b + head.r][b].method) {
				q.push(Node{ head.l - b + head.r, b, head.step + 1 });
				visit[head.l - b + head.r][b] = Path{ head.l, head.r, 5 };
			}
		}
		else if (!visit[0][head.r + head.l].method) {
			q.push(Node{ 0, head.r + head.l, head.step + 1 });
			visit[0][head.l + head.r] = Path{ head.l, head.r, 5 };
		}
		//  pour    2   to  1
		if (head.r >= a - head.l) {
			if (!visit[a][head.r - a + head.l].method) {
				q.push(Node{ a, head.r - a + head.l, head.step + 1 });
				visit[a][head.r - a + head.l] = Path{ head.l, head.r, 6 };
			}
		}
		else if (!visit[head.l + head.r][0].method) {
			q.push(Node{ head.l + head.r, 0, head.step + 1 });
			visit[head.l + head.r][0] = Path{ head.l, head.r, 6 };
		}
	}
	printf("impossible\n");
}
int main()
{
	scanf("%d%d%d", &a, &b, &aim);
	bfs();
	return 0;
}

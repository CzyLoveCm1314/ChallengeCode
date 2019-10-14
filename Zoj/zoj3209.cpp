#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxnode = 450100;
const int maxn = 505;
const int maxm = 905;
const int inf = 0x3f3f3f3f;

struct DLX{
	int n, m, size;
	int U[maxnode], D[maxnode], R[maxnode], L[maxnode], Row[maxnode], Col[maxnode];
	int H[maxn];//行头结点
	int S[maxm];//每一列有多少结点
	int ansd, ans[maxn];//如果有答案,择选了ansd行,放在ans[]数组里面0~ansd-1
	int minans;
	void init(int _n, int _m){
		n = _n, m = _m;
		minans = inf;
		for (int i = 0; i <= m; i++){
			S[i] = 0;
			U[i] = D[i] = i;//初始状态下,上下自己指向自己(也就知道了头结点的值为i)
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[m] = 0, L[0] = m;//环状,下面的Link一样也是环,这样，不管从一行中的任意一个结点都可以遍历完这一行.
		size = m;//编号,每列的头结点编号1-m，所以size从m+1开始
		for (int i = 1; i <= n; i++)H[i] = -1;
	}

	//第r行,第c列
	void link(int r, int c){
		++S[Col[++size] = c];//第size个结点的列为c,当前列的节点数++
		Row[size] = r;//第size个节点行位置为r
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if (H[r] < 0) H[r] = L[size] = R[size] = size;
		else{
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}

	//删除节点c(列c),并且删除所有在这一列的节点所在的行中的所有的节点。。
	void remove(int c){
		L[R[c]] = L[c];
		R[L[c]] = R[c];
		for (int i = D[c]; i != c; i = D[i])
			for (int j = R[i]; j != i; j = R[j]){
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				--S[Col[j]];
			}
	}

	//恢复节点c(列c),以及恢复所有在这一列的节点所在的行中的所有的节点。
	void resume(int c){
		for (int i = U[c]; i != c; i = U[i])
			for (int j = L[i]; j != i; j = L[j])
				++S[Col[U[D[j]] = D[U[j]] = j]];
		L[R[c]] = R[L[c]] = c;
	}

	//深度
	void dance(int d){
		if (R[0] == 0){
			if (d < minans)
				minans = d;
			return;
		}
		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])
			if (S[i] < S[c])
				c = i;
		remove(c);//找到节点数最少的列，当前元素不是原图上0,1的节点,而是列头结点
		for (int i = D[c]; i != c; i = D[i]){
			ans[d] = Row[i];//列头结点下面的一个节点
			for (int j = R[i]; j != i; j = R[j])
				remove(Col[j]);
			dance(d + 1);
			for (int j = L[i]; j != i; j = L[j])
				resume(Col[j]);
		}
		resume(c);
	}

};

DLX x;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--){
		int n, m, p;
		scanf("%d %d %d", &n, &m, &p);
		x.init(p, n*m);
		int x1, y1, x2, y2;
		for (int k = 1; k <= p; k++){
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			for (int i = x1; i < x2; i++)
				for (int j = y1; j < y2; j++)
					x.link(k, j*n + i + 1);
		}
		x.dance(0);
		if (x.minans == inf) puts("-1");
		else printf("%d\n", x.minans);
	}
	return 0;
}

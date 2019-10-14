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
	int H[maxn];//��ͷ���
	int S[maxm];//ÿһ���ж��ٽ��
	int ansd, ans[maxn];//����д�,��ѡ��ansd��,����ans[]��������0~ansd-1
	int minans;
	void init(int _n, int _m){
		n = _n, m = _m;
		minans = inf;
		for (int i = 0; i <= m; i++){
			S[i] = 0;
			U[i] = D[i] = i;//��ʼ״̬��,�����Լ�ָ���Լ�(Ҳ��֪����ͷ����ֵΪi)
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[m] = 0, L[0] = m;//��״,�����Linkһ��Ҳ�ǻ�,���������ܴ�һ���е�����һ����㶼���Ա�������һ��.
		size = m;//���,ÿ�е�ͷ�����1-m������size��m+1��ʼ
		for (int i = 1; i <= n; i++)H[i] = -1;
	}

	//��r��,��c��
	void link(int r, int c){
		++S[Col[++size] = c];//��size��������Ϊc,��ǰ�еĽڵ���++
		Row[size] = r;//��size���ڵ���λ��Ϊr
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

	//ɾ���ڵ�c(��c),����ɾ����������һ�еĽڵ����ڵ����е����еĽڵ㡣��
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

	//�ָ��ڵ�c(��c),�Լ��ָ���������һ�еĽڵ����ڵ����е����еĽڵ㡣
	void resume(int c){
		for (int i = U[c]; i != c; i = U[i])
			for (int j = L[i]; j != i; j = L[j])
				++S[Col[U[D[j]] = D[U[j]] = j]];
		L[R[c]] = R[L[c]] = c;
	}

	//���
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
		remove(c);//�ҵ��ڵ������ٵ��У���ǰԪ�ز���ԭͼ��0,1�Ľڵ�,������ͷ���
		for (int i = D[c]; i != c; i = D[i]){
			ans[d] = Row[i];//��ͷ��������һ���ڵ�
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

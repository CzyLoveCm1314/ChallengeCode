#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;
const int maxnode = 60000;
const int maxn = 4100;
const int maxm = 1100;

struct DLX{
	int n, m, size;
	int U[maxnode], D[maxnode], R[maxnode], L[maxnode], Row[maxnode], Col[maxnode];
	int H[maxn];//��ͷ���
	int S[maxm];//ÿһ���ж��ٽ��
	int ansd, ans[maxn];//����д�,��ѡ��ansd��,����ans[]��������0~ansd-1
	char cans[16 * 16 + 10];
	void init(int _n, int _m)
	{
		n = _n, m = _m;
		memset(cans, '\0', sizeof(cans));
		for (int i = 0; i <= m; i++)
		{
			S[i] = 0;
			U[i] = D[i] = i;//��ʼ״̬��,�����Լ�ָ���Լ�(Ҳ��֪����ͷ����ֵΪi)
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[m] = 0, L[0] = m;//��״,�����Linkһ��Ҳ�ǻ�,���������ܴ�һ���е�����һ����㶼���Ա�������һ��.
		size = m;//���,ÿ�е�ͷ�����1-m������size��m+1��ʼ
		for (int i = 1; i <= n; i++)
			H[i] = -1;
	}

	void link(int r, int c)//��r��,��c��
	{
		++S[Col[++size] = c];//��size��������Ϊc,��ǰ�еĽڵ���++
		Row[size] = r;//��size���ڵ���λ��Ϊr
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if (H[r] < 0)
			H[r] = L[size] = R[size] = size;
		else
		{
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}

	void remove(int c)//ɾ���ڵ�c(��c),����ɾ����������һ�еĽڵ����ڵ����е����еĽڵ㡣��
	{
		L[R[c]] = L[c];
		R[L[c]] = R[c];
		for (int i = D[c]; i != c; i = D[i])
			for (int j = R[i]; j != i; j = R[j])
			{
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				--S[Col[j]];
			}
	}

	void resume(int c)//�ָ��ڵ�c(��c),�Լ��ָ���������һ�еĽڵ����ڵ����е����еĽڵ㡣
	{
		for (int i = U[c]; i != c; i = U[i])
			for (int j = L[i]; j != i; j = L[j])
				++S[Col[U[D[j]] = D[U[j]] = j]];
		L[R[c]] = R[L[c]] = c;
	}

	bool dance(int d)//���
	{
		if (R[0] == 0){
			ansd = d;
			return true;
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
			if (dance(d + 1))return true;
			for (int j = L[i]; j != i; j = L[j])
				resume(Col[j]);
		}
		resume(c);
		return false;
	}
	void out(){
		int kinds, num;
		for (int i = 0; i < ansd; i++)
		{
			kinds = (ans[i] - 1) % 16 + 1;
			num = (ans[i] - 1) / 16 + 1;
			cans[num] = kinds - 1 + 'A';
		}
		int now = 1;
		for (int i = 1; i <= 16; i++)
		{
			for (int j = 1; j <= 16; j++)
				printf("%c", cans[now++]);
			printf("\n");
		}
	}
};

DLX x;
char s[20][20];
bool init(){
	char c;
	while (((c = getchar()) < 'A' || c > 'P') && c != '-'&&c != EOF);
	if (c == EOF)return 0;
	for (int i = 1; i <= 16; i++)
		for (int j = 1; j <= 16; j++){
			if (i == 1 && j == 1)s[i][j] = c;
			else{
				while (((c = getchar()) < 'A' || c > 'P') && c != '-');
				s[i][j] = c;
			}
		}
	return 1;
}

int main(){
	int T = 0;
	while (init()){
		if (T++)puts("");
		x.init(4096, 1024);
		for (int i = 1; i <= 16; i++)
			for (int j = 1; j <= 16; j++){
				int num = (i - 1) * 16 + j;
				int grid = (i - 1) / 4 * 4 + (j - 1) / 4 + 1;
				if (s[i][j] == '-'){
					for (int k = 1; k <= 16; k++){
						x.link((num - 1) * 16 + k, num);
						x.link((num - 1) * 16 + k, 16 * 16 + (i - 1) * 16 + k);
						x.link((num - 1) * 16 + k, 16 * 16 * 2 + (j - 1) * 16 + k);
						x.link((num - 1) * 16 + k, 16 * 16 * 3 + (grid - 1) * 16 + k);
					}
				}
				else{
					int k = s[i][j] - 'A' + 1;
					x.link((num - 1) * 16 + k, num);
					x.link((num - 1) * 16 + k, 16 * 16 + (i - 1) * 16 + k);
					x.link((num - 1) * 16 + k, 16 * 16 * 2 + (j - 1) * 16 + k);
					x.link((num - 1) * 16 + k, 16 * 16 * 3 + (grid - 1) * 16 + k);
				}
			}
		x.dance(0);
		x.out();
	}
}

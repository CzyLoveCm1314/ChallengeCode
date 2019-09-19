#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxnode = 50000;
const int MaxN = 500;
const int MaxM = 500;

struct DLX{
	int n, m, size;
	int U[maxnode], D[maxnode], R[maxnode], L[maxnode], Row[maxnode], Col[maxnode];
	int H[MaxN], S[MaxN];
	int ands, ans[MaxN];
	void init(int _n, int _m){
		n = _n;
		m = _m;
		for (int i = 0; i <= m; i++){
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[m] = 0; L[0] = m;
		size = m;
		for (int i = 1; i <= n; i++)
			H[i] = -1;
	}
	void Link(int r, int c){
		++S[Col[++size] = c];
		Row[size] = r;
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if (H[r] < 0)H[r] = L[size] = R[size] = size;
		else{
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}
	void remove(int c){
		for (int i = D[c]; i != c; i = D[i])
			L[R[i]] = L[i], R[L[i]] = R[i];
	}
	void resume(int c){
		for (int i = U[c]; i != c; i = U[i])
			L[R[i]] = R[L[i]] = i;
	}
	bool v[maxnode];
	int f(){
		int ret = 0;
		for (int c = R[0]; c != 0; c = R[c])v[c] = true;
		for (int c = R[0]; c != 0; c = R[c])
			if (v[c]){
				ret++;
				v[c] = false;
				for (int i = D[c]; i != c; i = D[i])
					for (int j = R[i]; j != i; j = R[j])
						v[Col[j]] = false;
			}
		return ret;
	}
	bool Dance(int d){
		if (d + f() > K)return false;
		if (R[0] == 0)return d <= K;
		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])
			if (S[i] < S[c])
				c = i;
		for (int i = D[c]; i != c; i = D[i]){
			remove(i);
			for (int j = R[i]; j != i; j = R[j])remove(j);
			if (Dance(d + 1))return true;
			for (int j = L[i]; j != i; j = L[j])resume(j);
			resume(i);
		}
		return false;
	}
};
DLX dlx;
int main() {


	return 0;
}
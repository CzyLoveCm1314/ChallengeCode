#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int a[maxn];
void quicksort(int a[], int left, int right) {
	if (left <=right) {
		int temp = a[left];
		int i = left;
		int j = right;
		int t;
		while (i < j) {
			while (a[j] >= temp &&i<j ) j--;
			while (a[i] <= temp && i<j ) i++;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		a[left] = a[i];
		a[j] = temp;
		quicksort(a, left, i - 1);
		quicksort(a, i + 1, right);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	printf("%d", a[0]);
	for (int i = 1; i < n; i++)printf(" %d", a[i]);


	return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
#define MAXN 500005
using namespace std;

int a[MAXN], n;
ll ans;

void Merge(int l, int mid, int r){
	int i = l, j = mid + 1;
	while (i <= mid && j <= r){
		if (a[i] <= a[j]) i++;
		else{
			j++;
			ans = ans + mid - i + 1;
		}
	}
	sort(a + l, a + r + 1);
	return;
}

void MergeSort(int l, int r){
	if (l < r){
		int mid = (l + r) / 2;
		MergeSort(l, mid);
		MergeSort(mid + 1, r);
		Merge(l, mid, r);
	}
	return;
}

int main(){
	while (scanf("%d", &n) != EOF && n){
		ans = 0;
		int i;
		for (i = 0; i < n; i++) scanf("%d", &a[i]);
		MergeSort(0, n - 1);
		printf("%lld\n", ans);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int inf = 0x3f3f3f3f;
int m, n;
int price[101][101];  
int lv[101];  
int x[101];
int dist[101];
bool vist[101];  

int dijkstra(){
	int node;
	int sd;
	int i, j;
	for (i = 1; i <= n; i++) dist[i] = price[0][i]; 
	for (i = 1; i <= n; i++) {
		node = 0;
		sd = inf;
		for (j = 1; j <= n; j++){
			if (!vist[j] && sd>dist[j])  {
				sd = dist[j];
				node = j;  
			}
		}
		if (node == 0)  break;
		vist[node] = true;
		for (j = 1; j <= n; j++){
			if (!vist[j] && price[node][j] > 0 && dist[j] > dist[node] + price[node][j])   
				dist[j] = dist[node] + price[node][j];
		}
	}
	return dist[1];  
}

int main() {
	while (~scanf("%d%d", &m, &n)) {
		memset(price, 0, sizeof(price));
		memset(lv, 0, sizeof(lv));
		memset(dist, inf, sizeof(dist));
		memset(vist, false, sizeof(vist));
		for (int i = 1; i <= n; i++){
			cin >> price[0][i] >> lv[i] >> x[i];  
			for (int j = 1; j <= x[i]; j++){
				int t, u;  
				cin >> t >> u;
				price[t][i] = u;   
			}
		}
		int temp_price;  
		int maxlv;  
		int minprice = inf; 
		for (int i = 1; i <= n; i++){
			maxlv = lv[i]; 
			for (int j = 1; j <= n; j++)  {
				if (lv[j]>maxlv || maxlv - lv[j]>m)   vist[j] = true;   
				else vist[j] = false;  
			}
			temp_price = dijkstra();
			if (minprice>temp_price)  minprice = temp_price;
		}
		cout << minprice << endl;
	}
	return 0;
}
#include<cstdio> 
#include<cstring>
#include<iostream>
using namespace std;

bool map[4][4] = { false }; 
int ans = 0x3f3f3f3f;    
bool flag;
int a[20], b[20];


void flip(int x, int y){
	int i, j;
	for (i = 0; i<4; i++){
		map[i][y] = !map[i][y]; 
	}
	for (j = 0; j<4; j++){
		if (j != y){
			map[x][j] = !map[x][j]; 
		}
	}
}


bool judge() {
	int i, j;
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			if (map[i][j] != true)
				return false;
	return true;
}


void dfs(int x, int y, int deep) {  
	if (judge()) {
		if (ans > deep) {
			ans = deep;
			return;
		}
	}
	if (x<0 || x>3 || y<0 || y>3) return;
	int nx, ny;
	nx = (x + 1) % 4;
	ny = y + (x + 1) / 4;
	flip(x, y);
	dfs(nx, ny, deep + 1);
	flip(x, y);
	dfs(nx, ny, deep);
}

void Dfs(int x, int y, int deep) { 
	if (judge()) {
		if (deep == ans)
			flag = true; 
		return;
	}
	if (flag || x<0 || x>3 || y<0 || y>3)  
		return;
	int nx, ny;
	nx = (x + 1) % 4;   
	ny = y + (x + 1) / 4;

	flip(x, y);
	Dfs(nx, ny, deep + 1);
	a[deep] = x;
	b[deep] = y; 
	flip(x, y);
	Dfs(nx, ny, deep);
}


int main() {
	char str[5];
	int i, j;
	for (i = 0; i<4; i++)
	{
		cin >> str;
		for (j = 0; j<4; j++)
			if (str[j] == '-')
				map[i][j] = true;
	}
	dfs(0, 0, 0); 

	flag = false;
	Dfs(0, 0, 0); 
	cout << ans << endl;
	for (i = 0; i<ans; i++) cout << a[i] + 1 << " " << b[i] + 1 << endl;
	return 0;
}
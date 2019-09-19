//
// Created by »Æå° on 2019-05-13.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int n, m, t;
int bx, by, fx, fy;
int flag = 0;
int isWalk[15][15];

void search(int x, int y){
	if (x == fx - 1 && y == fy - 1){
		flag++;
		return;
	}
	if (x<n &&x >= 0 && y >= 0 && y<m){
		if (x - 1 >= 0 && isWalk[x - 1][y] != 1)
		{
			isWalk[x - 1][y] = 1;
			search(x - 1, y);
			isWalk[x - 1][y] = 0;
		}
		if (x + 1<n &&isWalk[x + 1][y] != 1)
		{
			isWalk[x + 1][y] = 1;
			search(x + 1, y);
			isWalk[x + 1][y] = 0;
		}
		if (y - 1 >= 0 && isWalk[x][y - 1] != 1)
		{
			isWalk[x][y - 1] = 1;
			search(x, y - 1);
			isWalk[x][y - 1] = 0;
		}
		if (y + 1<m &&isWalk[x][y + 1] != 1)
		{
			isWalk[x][y + 1] = 1;
			search(x, y + 1);
			isWalk[x][y + 1] = 0;
		}
	}

}

int main(void)
{
	cin >> n >> m >> t;
	memset(isWalk, 0, sizeof(isWalk));
	cin >> bx >> by >> fx >> fy;
	int tx, ty;
	for (int i = 0; i < t; ++i) {
		cin >> tx >> ty;
		isWalk[tx - 1][ty - 1] = 1;
	}
	search(bx - 1, by - 1);
	cout << flag << endl;
	return 0;
}

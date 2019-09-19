#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

const int maxn = 50;
struct node {
	string temp;
	int step;
	node(){}
	node(string _temp,int _step):temp(_temp),step(_step){}
};
string a;
string b;
string a1[maxn];
string b1[maxn];
int cnt = 11;
int num = 0;
set<string> s;

void bfs(string start, string end) {
	queue<node> q;
	q.push(node(start, 0));
	while (!q.empty()) {
		node u = q.front();
		q.pop();
		if (u.temp == end) cnt = min(cnt, u.step);
		for (int i = 0; i < num; i++) {
			int index = 0;
			while (index < u.temp.size()) {
				index = u.temp.find(a1[i], index);
				if (index > u.temp.size())continue;
				else {
					string t = u.temp.substr(0, index) + b1[i] + u.temp.substr(index + a1[i].size());
					//cout << t << endl;
					if (!s.count(t)) {
						s.insert(t);
						if (u.step + 1 <= cnt) q.push(node(t, u.step + 1));
					}
				}
				index++;
			}
		}

	}
}

int main() {
	cin >> a >> b;
	int i = 0;
	while (cin >> a1[num] >> b1[num]) {
		num++;
	}
	bfs(a, b);
	if (cnt == 11) printf("NO ANSWER!\n");
	else printf("%d\n", cnt);

	return 0;
}
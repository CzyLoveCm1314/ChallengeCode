#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string in, post;

void getPre(string in,string post) {
	if (in.size()) {
		char key = post[post.size() - 1];
		cout << key;
		int cnt = in.find(key);
		getPre(in.substr(0, cnt), post.substr(0, cnt));
		getPre(in.substr(cnt + 1), post.substr(cnt,in.size()-cnt-1));
	}

}
int main() {
	cin.sync_with_stdio(false);
	cin >> in >> post;
	getPre(in,post);
	return 0;
}
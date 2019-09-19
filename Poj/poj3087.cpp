#include <cstdio>
#include<iostream>
#include <map>
#include <cstring>
#include <string>
using namespace std;

int main(){
	int n, c, t = 0, cut, i;
	scanf("%d", &n);
	while (n--){
		scanf("%d", &c);
		t++;
		cut = 0;
		char s1[110], s2[110], s12[220], s[220];
		scanf("%s%s%s", s1, s2, s12);
		map <string, int > map1;
		int len, flag = 0;
		while (1){
			cut++;
			len = 0;
			for (i = 0; i< c; i++){
				s[len] = s2[i];
				len++;
				s[len] = s1[i];
				len++;
			}
			s[len] = '\0';
			if (strcmp(s, s12) == 0){
				flag = 1;
				break;
			}
			if (map1.find(s) != map1.end()) break;
			map1[s] = 0;
			for (i = 0; i<c; i++){
				s1[i] = s[i];
				s2[i] = s[i + c];
			}
		}
		if (flag) printf("%d %d\n", t, cut);
		else printf("%d -1\n", t);
	}
	return 0;
}
